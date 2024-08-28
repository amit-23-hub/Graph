 bool detectCycle(int node, int pre ,  vector<bool>&visited , vector<int>adj[]){
       
       visited[node] = 1 ;
       for(int i = 0 ; i<adj[node].size() ; i++){
           
           // ignoring previos node for cycle detection 
           if(pre == adj[node][i]){
               continue  ; 
           }
           // if found visited node then return treue 
           if(visited[adj[node][i]]){
               return 1 ;
           }
           // check for other node if present loop then return true 
           if(detectCycle(adj[node][i],node , visited , adj)){
               return 1 ;
           }
           
          
       }
        return 0 ; 
        
   }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,0) ; 
        int pre = -1 ; 
        
        // graph can be connect or non connected so in that case it might be possibility that loop presetn in other part 
        // we will visit all vertices
        
        for(int  i = 0 ; i<V ; i++){
            if(!visited[i]){
                // us vertices ko bhej dunga function me agr present rahgea to return true 
                if(detectCycle(i , pre , visited , adj)){
                    return 1  ; 
                }
            }
        }
        return  0 ;
    }