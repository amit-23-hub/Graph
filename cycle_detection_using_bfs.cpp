

bool bfs(int v , vector<int>adj[] , vector<bool>visited){

    queue<pair<int,int>>q ; 
    visited[v] = 1 ; 

    q.push<make_pair(v,-1) ; 

    while(!q.empty()){
        int node  = q.front().first ; 
        int pre =  q.front().second ; 
        q.pop() ; 

        for(int i = 0 ; i<adj[node].size() ; i++ ){
            if(pre == adj[node][i]){
                continue ; 
            }
            if(visited[adj[node][i]]){
                return true ; 
            }
            else{
                visited[adj[node][i]] = 1 ; 
                q.push(make_pair(adj[node][i] , node)) ; 
            }
        }
    }
}


bool detectcycle(int V ,  vector<int>adj[]){
    vector<bool>visited ; 


    for(int i = 0 ; i<v ; i++){
        if(!visited[i] && bfs(i ,visited , adj)){
            return 1   ;
        }
    }
    return 0  ; 
}