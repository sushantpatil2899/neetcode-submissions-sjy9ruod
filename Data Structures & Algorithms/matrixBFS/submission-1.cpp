class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        deque<pair<int, int>> dq;
        vector<vector<int>> visit(rows, vector<int>(cols,0));

        int length = 0;
        dq.push_back({0,0});
        visit[0][0] = 1;
        while (dq.size()) {
            int dq_size = dq.size();
            for (int i=0; i<dq_size; i++) {
                pair<int, int> point = dq.front();
                dq.pop_front();
                if (point.first==rows-1 && point.second==cols-1) {
                    return length;
                }

                vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
                for (pair<int, int> dir: directions) {
                    int r_coord = point.first + dir.first;
                    int c_coord = point.second + dir.second;

                    if (min(r_coord, c_coord)<0 || r_coord==rows || c_coord==cols || grid[r_coord][c_coord]==1 || visit[r_coord][c_coord]==1) continue;
                    dq.push_back({r_coord, c_coord});
                    visit[r_coord][c_coord] = 1;
                }

            }
            length++;
        }
        return -1;
    }
};
