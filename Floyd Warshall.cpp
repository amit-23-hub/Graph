	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int n  = matrix.size(); 
	    
	    // question me jaha path nhi diya tha vah -1 tha bs usi ko chnage kiye hai 
	    for(int i = 0 ; i<n ; i++){
	        for(int j  = 0 ; j<n ; j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j] = INT_MAX  ; 
	            }
	        }
	    }
	    
	    // appying floyd warshall method 
	    
	    
	    for(int k = 0 ; k<n; k++){
	        
	        for(int  i = 0 ; i<n ; i++){
	            for(int j = 0 ; j<n ; j++){
	                
	                // integer overflow ko handle kr lete hai 
	                if(matrix[k][j]==INT_MAX || matrix[i][k]==INT_MAX) continue ;
	                
	                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]) ; 
	            }
	        }
	    }
	    
	    // abb jaha INT_MAX the unko -1 kr do 
	    for(int i = 0 ; i<n ; i++){
	        for(int j  = 0 ; j<n ; j++){
	            if(matrix[i][j]== INT_MAX){
	                matrix[i][j] = -1 ; 
	            }
	        }
	    }
	    
	    
	    
	}