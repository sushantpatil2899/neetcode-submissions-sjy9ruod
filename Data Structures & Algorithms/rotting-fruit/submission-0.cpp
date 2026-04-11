class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        deque<pair<int,int>> dq;
        vector<vector<int>> visit(rows, vector<int>(cols,0));

        for (int r = 0; r<rows; r++) {
            for (int c = 0; c<cols; c++) {
                if (grid[r][c] == 2) {
                    dq.push_back({r,c});
                    visit[r][c] = 1;
                }
            }
        }
        int minutes = 0;
        while (dq.size()) {
            int size = dq.size();
            for (int i = 0; i<size; i++) {
                pair<int, int> point = dq.front();
                dq.pop_front();

                vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                for (vector<int> d:dir) {
                    int r = point.first + d[0];
                    int c = point.second + d[1];

                    if (min(r,c)<0 || r==rows || c==cols || grid[r][c] == 0 || grid[r][c] == 2 || visit[r][c]==1) continue;
                    grid[r][c] = 2;
                    visit[r][c] = 1;
                    dq.push_back({r,c});
                }
            }
            minutes++;
        }

        for (int r = 0; r<rows; r++) {
            for (int c = 0; c<cols; c++) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }

        if (minutes) return minutes-1;
        return minutes;
    }
};