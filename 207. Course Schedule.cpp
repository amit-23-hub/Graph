class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> InDeg(numCourses, 0);

        // Create adjacency list and calculate in-degree of each node
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];   // second part 
            int v = prerequisites[i][0];   // first part 
            adj[u].push_back(v);
            InDeg[v]++;
        }

        queue<int> q;

        // Push all nodes with in-degree 0 to the queue
        for (int i = 0; i < numCourses; i++) {
            if (InDeg[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        // Process nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i];
                InDeg[neighbor]--;
                if (InDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        
        return cnt == numCourses;
    }
};