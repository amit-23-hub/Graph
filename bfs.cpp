vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans  ; 
        queue<int>q ; 
        vector<bool>visited(V,0);
        
        q.push(0) ; 
        visited[0] = 1 ;
        
        while(!q.empty()){
            
          int   node = q.front() ; 
            q.pop() ;
            ans.push_back(node) ; 
            
            for(int  i = 0 ; i<adj[node].size()  ; i++){
                
                if(!visited [adj[node][i] ]){
                   visited [adj[node][i] ]=1 ;
                   q.push(adj[node][i])   ;
                }
            }
            
            
        }
        
        return ans  ; 