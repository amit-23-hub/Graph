#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Define direction 
    int row[8] = {1, 1, -1, -1, 0, 0, 1, -1};
    int col[8] = {1, -1, 1, -1, 1, -1, 0, 0};
    

    bool valid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the starting or ending cell is blocked(1), return -1
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // Queue stores (row, col, step count)
        queue<pair<int, pair<int, int>>> q;
        
        // Initialize a visited matrix to track visited cells
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        // Start BFS from the top-left corner (0, 0) with a step count of 1
        q.push({0, {0, 1}});
        visited[0][0] = 1;

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();

            // Check if we've reached the bottom-right cell
            if (i == n - 1 && j == n - 1) {
                return step;
            }

            // Explore all 8 possible directions
            for (int k = 0; k < 8; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];

                // Check if the new cell is within bounds, unvisited, and not blocked
                if (valid(new_i, new_j, n) && grid[new_i][new_j] == 0 && visited[new_i][new_j] == 0) {
                    // Mark as visited
                    visited[new_i][new_j] = 1;
                    
                    // Push the new cell into the queue with the incremented step count
                    q.push({new_i, {new_j, step + 1}});
                }
            }
        }

      
        return -1;
    }
};
