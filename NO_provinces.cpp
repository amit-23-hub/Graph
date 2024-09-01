class Solution {
public:
    void bfs(int i, unordered_map<int, vector<int>>& adj, vector<int>& visited) {
        visited[i] = 1;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                if (!visited[adj[node][j]]) {
                    visited[adj[node][j]] = 1;
                    bfs(adj[node][j], adj, visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> visited(isConnected.size(), 0);

        // Making adj list from 2d matrix
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                bfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};