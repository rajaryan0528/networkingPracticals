
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V; // No. of vertices

    //to store vertex and weight pair for every edge
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{
    // Create a set to store vertices that are being processed
    set<pair<int, int>>st;
    vector<int> dist(V,INT_MAX);

    // Insert source itself in Set and initialize its distance as 0.
    st.insert(make_pair(0, src));
    dist[src] = 0;

    /* Looping till all shortest distance are finalized then set will become empty */
    while (!st.empty())
    {
        // The first vertex in Set is the minimum distance vertex, extract it from set.
        pair<int, int> top = *(st.begin());
        st.erase(st.begin());

        // vertex label is stored in second of pair (ithas to be done this way to keep the vertice sorted distance (distance must be   first item in pair)
        int node = top.second;   //vertex

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adj[node].begin(); i != adj[node].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of node.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[node] + weight)
            {
                /* If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here. */
                if (dist[v] != INT_MAX)
                    st.erase(st.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[node] + weight;
                st.insert(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    cout<<"Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout<<dist[i]<<" "<<endl;
}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above figure
    int V = 3;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 0, 3);
    g.shortestPath(0);
    return 0;
}
