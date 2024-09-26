  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> dist(V, INT_MAX); 
    vector<bool> explore(V, 0);
    
    dist[S] = 0;  // Distance of source to itself is 0

    for (int cnt = 0; cnt < V; cnt++) {
        // Find the minimum distance node which is not explored
        int node = -1, value = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (!explore[i] && value > dist[i]) {
                node = i;
                value = dist[i];
            }
        }

        explore[node] = 1;  // Mark the selected node as explored

        // Relax the neighbors of the selected node
        for (int j = 0; j < adj[node].size(); j++) {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if (!explore[neighbour] && dist[node] + weight < dist[neighbour]) {
                dist[neighbour] = dist[node] + weight;
            }
        }
    }

    return dist;
}