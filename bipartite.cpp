class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size(); 
        vector<int> color(V, -1); 
        queue<int> q; 

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // If the node hasn't been colored yet
                color[i] = 0; 
                q.push(i); 

                while (!q.empty()) {
                    int node = q.front(); 
                    q.pop(); 

                    // Look at neighbors
                    for (int neighbor : graph[node]) {
                        // If the neighbor hasn't been colored, assign it the opposite color
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node]; // Alternate color
                            q.push(neighbor);  
                        } else if (color[neighbor] == color[node]) {
                            // If the neighbor has the same color as the current node, it's not bipartite
                            return false; 
                        }
                    }
                }
            }
        }
        return true; 
    }
};
