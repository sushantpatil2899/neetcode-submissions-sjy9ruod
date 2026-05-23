class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (fresh > 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];

                    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1) continue;
                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                }
            }
            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
