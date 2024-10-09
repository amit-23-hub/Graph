 void dfs (int node  ,  vector<bool>&visited , vector<int>adj[]){
         visited[node] = 1 ; 
         for(int i = 0 ; i<adj[node].size() ; i++){
         if(!visited[adj[node][i]]){
             dfs(adj[node][i] , visited, adj ) ; 
         }
         }
     }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    
	    
	    vector<int>deg(V,0); 
	    
	    int odd_deg = 0 ; 
	    // calculating degree 
	    for(int i = 0 ; i<V ;i++){
	       deg[i]=adj[i].size() ;
	       
	       if(!deg[i]%2){
	           odd_deg ++ ; 
	       }
	    }
	    
	    // agr odd degree 2&  0   na ho to  na EC na EP hoga so return 0  
	    
	    if(odd_deg!=2 && odd_deg != 0 ){
	        return 0  ;  
	    }
	    
	    
	    /// abb hme check krna hai ki graph connnected hai ya nhi 
	    
	    
	    vector<bool>visited(V , 0) ; 
	    
	    // applyinkg dfs 
	    
	    for(int  i = 0 ; i<V ;  i++){
	        if(deg[i]){
	            dfs(i ,  visited  , adj ) ; 
	            break ;  
	        }
	    }
	    
	    // agr node visited ni hai degree   and degree 0 nhi hai to  return  0  
	    
	    
	    for(int i = 0 ; i<V ; i++){
	        
	        
	        if(deg[i] && !visited[i]){
	            return  0  ;
	        }
	    }
	    
	    
	    // now iff odd  = 0  EC else EP 
	    if(odd_deg==0){
	        return 2  ;  
	    }else{
	        return 1  ;   
	    }
	}