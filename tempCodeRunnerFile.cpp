void dijkstra(int src)
//     {
//         bool visited[MAX_NODES];

//         for (int i = 0; i < vertices; i++)
//         {
//             visited[i] = false;     // mark node as not processed
//             distances[i] = INT_MAX; // set distance from src as infinity
//         }

//         // mark the src node
//         path[src] = -1;
//         distances[src] = 0;

//         // iterate over all vertices
//         for (int i = 0; i < vertices - 1; i++)
//         {
//             // find the nearest unprocessed node
//             int u = minDistance(visited);
//             // mark node as processed
//             visited[u] = true;
//             // iterate over all nodes
//             for (int v = 0; v < vertices; v++)
//                 // update distance for unprocessed node if there
//                 // exists an edge(u,v) and new distance is lesser
//                 // also add the node to the shortest path
//                 if (visited[v] == false &&
//                     adjMatrix[u][v] &&
//                     distances[u] != INT_MAX &&
//                     distances[u] + adjMatrix[u][v] < distances[v])
//                 {
//                     path[v] = u;
//                     distances[v] = distances[u] + adjMatrix[u][v];
//                 }
//         }

//         // print distances and shortest paths
//         cout << "\nDest Node \t Distance \t Shortest Path";
//         cout << "\n========= \t ======== \t =============";
//         for (int i = 0; i < vertices; i++)
//         {
//             cout << endl
//                  << (i + 1)
//                  << " \t\t " << distances[i]
//                  << " \t\t " << (src + 1);
//             printShortestPath(i);
//         }
//     }

//     cout << "Enter Source Node: ";
//     cin >> v;

//     graph.dijkstra(v - 1);

//     return 0;
// }

// vector<int> dijkstra(int src)
// {
//     bool visited[MAX_NODES];

//     for (int i = 0; i < vertices; i++)
//     {
//         visited[i] = false;     // mark node as not processed
//         distances[i] = INT_MAX; // set distance from src as infinity
//     }

//     // mark the src node
//     path[src] = -1;
//     distances[src] = 0;

//     // iterate over all vertices
//     for (int i = 0; i < vertices - 1; i++)
//     {
//         // find the nearest unprocessed node
//         int u = minDistance(visited);
//         // mark node as processed
//         visited[u] = true;
//         // iterate over all nodes
//         for (int v = 0; v < vertices; v++)
//             // update distance for unprocessed node if there
//             // exists an edge(u,v) and new distance is lesser
//             // also add the node to the shortest path
//             if (visited[v] == false &&
//                 adjMatrix[u][v] &&
//                 distances[u] != INT_MAX &&
//                 distances[u] + adjMatrix[u][v] < distances[v])
//             {
//                 path[v] = u;
//                 distances[v] = distances[u] + adjMatrix[u][v];
//             }
//     }

//     // print distances and shortest paths
//     cout << "\nDest Node \t Distance \t Shortest Path";
//     cout << "\n========= \t ======== \t =============";
//     for (int i = 0; i < vertices; i++)
//     {
//         cout << endl
//              << (i + 1)
//              << " \t\t " << distances[i]
//              << " \t\t " << (src + 1);
//         printShortestPath(i);
//     }
// }