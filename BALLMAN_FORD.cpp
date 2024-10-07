 vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        
        vector<int>dist(V,1e8) ;
        int e  =  edges.size() ;
        dist[S]=0 ; 
        // relax edge v-1 times 
        for(int  i = 0 ; i<V-1 ; i++){
           bool  flag = 0 ; 
            
            
            for(int   j  = 0 ; j<edges.size() ; j++){
                int u =  edges[j][0] ;
                  int v =  edges[j][1] ;
                    int wt =  edges[j][2] ;
                    
                    
                    
                    if(dist[u]==1e8) continue ; 
                    
                    if(dist[u]+wt <dist[v]){
                        
                        flag = 1 ; 
                        dist[v] = dist[u] + wt ; 
                    }
            }
            
        }
        
        // relax one more time to detect te negative cycle
        
        for(int j = 0 ; j<e ; j++){
            int u =  edges[j][0] ;
            int v =  edges[j][1] ;
            int wt =  edges[j][2] ;
                    
                    if(dist[u]==1e8) continue ; 
                    
                    
                    
                    if(dist[u]+wt <dist[v]){
                        // cycle detected 
                       vector<int>ans ;
                       ans.push_back(-1) ; 
                       
                       return ans  ;
                    }
            
        }
        
        return dist   ;  