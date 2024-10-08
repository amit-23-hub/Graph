class Solution {
  public:
  
     int row[4] = {1,-1,0,0} ;
     int col[4] = {0,0,-1,1 } ;
     
     bool validate(int i , int j ,  int m , int n ){
         return i>=0&&i<m&&j>=0&&j<n ; 
     }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        
        // handling edge case  
        
        // if source node is  0  
        if(!A[0][0]){
            return  -1 ; 
        }
        
        
        // if sorce node is equal to destination  
        
        if(X==0 && Y==0){
            return 0 ; 
        }
           // row , col , step 
        queue<pair<int , pair<int,int>>>q ; 
        
        q.push({0,{0,0}}) ; 
        A[0][0] = 0 ;    ///  mark source node visted  
        while(!q.empty()){
            
            int i = q.front().first ; 
             int j = q.front().second.first ; 
              int s = q.front().second.second ; 
              
              q.pop() ; 
              
              // now moveing up down left right is decided by direction  
              
              for(int k = 0 ; k<4 ; k++){
                  int new_i = i+row[k] ; 
                  int new_j = j +col[k] ; 
                  
                  // validated & check visited and increase step  
                  
                  if(validate(new_i , new_j , N,M)&& A[new_i][new_j]==1){
                      
                      if(new_i==X && new_j==Y){
                          return s+1 ; 
                      }
                      // mark visited  
                      A[new_i][new_j]=0 ; 
                      
                      // push into queue ; 
                      q.push({new_i,{new_j , s+1}}) ; 
                  }
              }
        }
        
        
        return -1 ;   // in the case when shortest path is not found  
        
    }