class Solution {
public:
    int r, c;

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> distances(r, vector<int>(c, -1));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    distances[i][j] = 0; // Mark as visited and distance 0
                }
            }
        }

        while (!q.empty()) {
            int ni = q.front().first;
            int nj = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newI = ni + row[k];
                int newJ = nj + col[k];

                if (valid(newI, newJ) && distances[newI][newJ] == -1) {
                    distances[newI][newJ] = distances[ni][nj] + 1;
                    q.push({newI, newJ});
                }
            }
        }

        return distances;
    }
};