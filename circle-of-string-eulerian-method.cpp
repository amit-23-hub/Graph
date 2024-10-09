 void dfs (int node , vector<int>adj[] , vector<bool>&visited ){
         visited[node]=1  ;
         for(int  i = 0 ; i<adj[node].size() ; i++){
             if(!visited[adj[node][i]]){
                 dfs(adj[node][i] , adj , visited) ; 
             }
         }
     }
    int isCircle(vector<string> &arr) {
        // code here
        
        
        vector<int>adj[26] ;
        
        vector<int>indeg(26,0) ; 
        vector<int>outdeg(26,0) ; 
        
        for(int i = 0 ; i<arr.size() ; i++){
            
            string s = arr[i] ; 
            int  u = s[0]-'a' ; 
            int v = s[s.size()-1] - 'a' ; 
            
            adj[u].push_back(v) ; 
            
            outdeg[v]++ ; 
            indeg[u]++ ; 
        }
        // abb eulerian circuit chek kr lena hai 
        
        // agr indegee not equal to out degree hogi to return 0  kr dena kyuki vo eulerian circuit nhib  ho skta 
        
        for(int i = 0 ; i<26 ; i++){
            if(indeg[i]!=outdeg[i]){
                return 0 ; 
            }
        }
        
        // dfs laga dena hai so that we can check all node are connected or not 
        
        vector<bool>visited(26,0) ; 
        int node =  arr[0][0] - 'a' ;    // arr[0] = abc and arr[0][0] = a  
        
        dfs(node ,  adj ,  visited ) ; 
        
        for(int i = 0 ; i<26 ; i++){
            if(indeg[i]&&!visited[i]){
                return 0 ; 
            }
        }
        
        
        return 1  ; 
    }