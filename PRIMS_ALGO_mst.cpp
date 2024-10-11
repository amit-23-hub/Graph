	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       // wt , node , parent 
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minH; 
    vector<int> IsMst(V, 0); 
    vector<int> parent(V);
    int cost = 0;

    minH.push({0, {0, -1}}); 

    while (!minH.empty()) {
        int wt = minH.top().first; 
        int node = minH.top().second.first; 
        int par = minH.top().second.second; 
        minH.pop();

        // agr vo mst me nhi hoga to visit kr lenege
        if (!IsMst[node]) {
            IsMst[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int i = 0; i < adj[node].size(); i++) {
                if (!IsMst[adj[node][i][0]]) {
                    minH.push({adj[node][i][1], {adj[node][i][0], node}});
                }
            }
        }
    }
    return cost;}