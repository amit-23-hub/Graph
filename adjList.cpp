vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(int i =0 ; i< edges.size() ; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            
            adjList[v].push_back(u) ;
            adjList[u].push_back(v) ; 
        }
        
        return adjList ; 
    }