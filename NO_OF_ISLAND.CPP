class Solution {
public:
    int r, c;

    // direction arrays for 8 directions
    int row[8] = {-1, 1,  0, 0};
    int col[8] = {0,0, 1, -1};

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        r = grid.size();
        c = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // found '1'
                if (grid[i][j] == '1') {
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0'; // mark as visited
                    
                    // explore all connected '1's
                    while (!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();  // pop the current cell from the queue
                        
                        // check 8 directions
                        for (int k = 0; k < 4; k++) {
                            int ni = new_i + row[k];
                            int nj = new_j + col[k];
                            
                            if (valid(ni, nj) && grid[ni][nj] == '1') {
                                grid[ni][nj] = '0'; // mark as visited
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
