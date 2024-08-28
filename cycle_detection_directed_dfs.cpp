 bool detectCycle(int node , vector<int>adj[] , vector<bool>&path , vector<bool>&visited){
       
       path[node] = 1 ; 
       visited[node] = 1 ; 
       for(int  i = 0 ; i<adj[node].size() ; i++){
           
           // if allready present return true 
           if(path[adj[node][i]]){
               return 1 ; 
           }
           // ager visited hai to traverse nhi krenge agr ek bar trverse krne ke badd nhi hua ot aage bhi nhi hoga 
           if(visited[adj[node][i]]){
               continue  ; 
           }
           if(detectCycle(adj[node][i], adj , path , visited)){
               return 1 ; 
           }
       }
       
       path[node] = 0 ; 
       
       return 0 ;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>path(V,0) ; 
        vector<bool>visited(V ,0) ; 
        
        
        for(int  i = 0 ; i<V ; i++){
            if(!visited[i] && detectCycle(i , adj , path , visited)){
                return 1 ; 
            }
        }
        
        
        return 0 ; 
     
    }