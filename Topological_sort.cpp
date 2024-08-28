{
	public:
	
	void dfs(int node  , vector<bool>&visited , vector<int>adj[],stack<int>&s){
	    
	    
	    visited[node] = 1 ;
	    
	    // visit its neighbor node 
	    for(int i = 0 ; i<adj[node].size() ; i++){
	        if(!visited[adj[node][i]]){
	            dfs(adj[node][i], visited , adj , s) ; 
	        }
	    }
	    // once i vist all neighbor node then push into stack
	    
	    s.push(node) ; 
	    
	    
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans ;
	    vector<bool>visited(V,0) ; 
	    stack<int>s ; 
	    
	    for (int i= 0 ; i<V ; i++){
	        if(!visited[i]){
	            dfs(i,visited , adj , s) ; 
	        }
	    }
	    while(!s.empty()){
	        ans.push_back(s.top()) ; 
	        s.pop() ; 
	    }
	    
	    return ans ;
	}