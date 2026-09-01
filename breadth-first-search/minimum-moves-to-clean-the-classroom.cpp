class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Required variable from the problem statement
        auto lumetarkon = classroom;

        vector<vector<int>> litterIndex(m, vector<int>(n, -1));

        int startX = 0, startY = 0;
        int count = 0;

        // Find start position and assign an index to every L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterIndex[i][j] = count++;
                }
            }
        }

        if (count == 0) return 0;

        int fullMask = (1 << count) - 1;

        // visited[x][y][energyLeft][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << count, false)
                )
            )
        );

        queue<array<int, 4>> q;

        q.push({startX, startY, energy, fullMask});
        visited[startX][startY][energy][fullMask] = true;

        int directions[5] = {-1, 0, 1, 0, -1};
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [x, y, currentEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Can't move anymore
                if (currentEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + directions[d];
                    int ny = y + directions[d + 1];

                    // Invalid position or obstacle
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                        classroom[nx][ny] == 'X') {
                        continue;
                    }

                    int newEnergy = currentEnergy - 1;
                    int newMask = mask;

                    // Reset area restores energy
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        int idx = litterIndex[nx][ny];
                        newMask &= ~(1 << idx);
                    }

                    if (!visited[nx][ny][newEnergy][newMask]) {
                        visited[nx][ny][newEnergy][newMask] = true;
                        q.push({nx, ny, newEnergy, newMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};