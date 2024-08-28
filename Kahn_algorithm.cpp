// find all element Indegreee  of all vertix 
// push zero Indegree vertex in the queue 
// pop element from the quueu 
// now decrease the indegree of each neighbhor element of node  if any one degree become 0 then push into queue 



vector<int>toposort(int V , vector<int>adj[]){

    // for storing ans 
    vector<int>ans ; 
    // indegree
    vector<int>Indeg(V , 0) ;

    for(int i = 0 ; i<V ; i ++){
        for(int  j = 0 ; j<adj[i].size(); j++){
            Indeg[adj[i][j]]++ ; 
        }
    }

    // push all 0  indeg into queue 

    queue<int>q ; 
 
 for(int  i = 0 ; i<V ; i++){
    if(Indeg[i]==0){
        q.push(i)  ;
    }
 }

 while(!q.empty()){
    int  node = q.front() ; 
    q.pop() ; 
    ans.push_back(node) ; 

    for(int  i = 0 ; i<adj[node].size() ; i++){
        Indeg[adj[node][i]]-- ;

        if(Indeg[adj[node][i]]==0){
            q.push(adj[node][i]) ;
        }
    }
 }
 return ans ; 

}
