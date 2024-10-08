int row[8]  = {2, 2, -2, -2, 1, 1, -1, -1};
int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};

// validate the position
bool valid(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    // given indexing starts with 1, so decrease all by 1
    KnightPos[0]--;
    KnightPos[1]--;
    TargetPos[0]--;
    TargetPos[1]--;

    // case when starting position is equal to the target
    if (TargetPos[0] == KnightPos[0] && TargetPos[1] == KnightPos[1]) {
        return 0;
    }

    // queue stores row, col, and step count
    queue<pair<int, pair<int, int>>> q;

    vector<vector<int>> chess(N, vector<int>(N, 0));

    q.push({KnightPos[0], {KnightPos[1], 0}});
    chess[KnightPos[0]][KnightPos[1]] = 1;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second.first;
        int step = q.front().second.second;

        q.pop();

        // explore all 8 possible directions
        for (int k = 0; k < 8; k++) {
            int new_i = i + row[k];
            int new_j = j + col[k];

            // check for validation and if it is unvisited
            if (valid(new_i, new_j, N) && chess[new_i][new_j] == 0) {
                // check if we have reached the destination
                if (new_i == TargetPos[0] && new_j == TargetPos[1]) {
                    return step + 1;
                }

                // mark as visited
                chess[new_i][new_j] = 1;

                // push into the queue
                q.push({new_i, {new_j, step + 1}});
            }
        }
    }

    // return -1 if no valid path found
    return -1;
}