 // recursive dfs 
  
  void  DFS(int node , vector<bool>&visited , vector<int>&ans , vector<int>adj[]) {
      
      
      visited[node] =  1 ; 
      ans.push_back(node) ; 
      
      for(int i = 0 ; i<adj[node].size() ; i++){
          if(!visited[adj[node][i]]){
              DFS(adj[node][i] , visited , ans , adj) ; 
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        // Code here
        vector<bool>visited(V,0) ; 
        vector<int>ans ;
        DFS(0,visited , ans , adj) ; 
        
        return ans ; 
    }