class Solution {
public:
    int r ;
    int c ; 
    int row[4] = {1,-1,0,0} ; 
    int  col[4] = {0,0,-1,1} ; 

    /// checking validation  
 
    bool valid(int  i ,  int  j ){
           return i>=0&&i<r&&j>=0&&j<c ; 
    }
     
    void solve(vector<vector<char>>& board) {
        
        r = board.size() ; 
        c = board[0].size() ; 
        queue<pair<int,int>>q ;

        // row first 
        for(int i = 0 ; i<c ; i++){
            if(board[0][i]=='O'){
                q.push(make_pair(0,i)) ; 
                board[0][i]='t' ; 
            }
        } 
        // first col 
        for(int i = 1 ; i<r ; i++){
            if(board[i][0]=='O'){
                q.push(make_pair(i,0)) ; 
                board[i][0]='t' ; 
            }
        }

        // last row 
          for(int i = 1 ; i<c ; i++){
            if(board[r-1][i]=='O'){
                q.push(make_pair(r-1,i)) ; 
                board[r-1][i]='t' ; 
            }
        }
             // last col  
          for(int i = 1 ; i<r-1 ; i++){
            if(board[i][c-1]=='O'){
                q.push(make_pair(i,c-1)) ; 
                board[i][c-1]='t' ; 
            }
        }

        // apply bfs and make its connected ceil to t

        while(!q.empty()){
            int  ni =  q.front().first ; 
            int nj  = q.front().second ; 
            q.pop() ; 
            

             for(int  k = 0 ; k<4 ;  k++){
                if(valid(ni+row[k],nj+col[k])&& board[ni+row[k]][nj+col[k]]=='O'){
                    board[ni+row[k]][nj+col[k]]='t' ; 
                    q.push(make_pair(ni+row[k] ,nj+col[k] ))  ; 
                }
             }
        }

             // change rest 0 to x and t tp 0 

            for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 't') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};