   bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // solve using kahn algo 
        int count=0 ; 
        vector<int>Indeg(V ,0) ;
        
        // indegree find kr di
        for(int i = 0 ; i<V ; i++){
            for(int j = 0 ; j<adj[i].size();j++)
            Indeg[adj[i][j]]++ ; 
        }
        
        
        //push all 0s indegree into queue 
        queue<int>q ; 
        
        for(int i = 0 ;  i<V ; i++){
            if(!Indeg[i])
            q.push(i) ;
        }
        
        while(!q.empty()){
            int node  =  q.front() ; 
            q.pop() ; 
            count++ ; 
            
            // decreasing degree of neighbor 
            for(int  i = 0 ; i<adj[node].size(); i++){
                Indeg[adj[node][i]]-- ; 
                if(Indeg[adj[node][i]]==0)
                q.push(adj[node][i]) ; 
            }
        }
        
        return count!=V ; 
    }