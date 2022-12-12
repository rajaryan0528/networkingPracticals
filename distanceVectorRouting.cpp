
// distance vector routing

// what makes it better then dijkstra
/* Negetive edges
    -> it wil work for edges and negative cycles
    -> it can detect negative cycles as well  */

#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;

int main()
{
    int n, m; // 5 8
    cout << "Enter number of routers: ";
    cin >> n;
    cout << "Enter number of links: ";
    cin>> m;
    
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;        //src,dest,cost
        cout<<"Enter src :";
        cin >> u ;
        cout<<"Enter dest :";
        cin>>v;
        cout<<"Enter cost :";
        cin>>w;
        edges.push_back({u, v, w});
    }
    int src;
    for (int i=0;i<n;i++)
    {
    src=i;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int it = 0; it < n - 1; it++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], w + dist[u]);
        }
    }
    cout<<"For router "<<i<<"...."<<endl;
    for (auto i : dist)
        cout << i << " ";
    cout << "---------------\n";
    }
}