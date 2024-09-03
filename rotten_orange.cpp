class Solution {
public:
    int r, c; 
    int ro[4] = {0, 0, 1, -1};
    int co[4] = {-1, 1, 0, 0};

    // Checking whether it is within bounds or not 
    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;

        // Pushing all rotten oranges into the queue 
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        // BFS to rot all reachable fresh oranges
        while (!q.empty()) {
            int cur_rotten = q.size();
            bool anyRotting = false; // Track if any fresh orange rots during this round

            while (cur_rotten--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + ro[k], nj = j + co[k];
                    if (valid(ni, nj) && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push(make_pair(ni, nj));
                        anyRotting = true;
                    }
                }
            }

            if (anyRotting) {
                time++; // Increment time only if any fresh orange was rotted
            }
        }

        // Check if there's any fresh orange left
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
