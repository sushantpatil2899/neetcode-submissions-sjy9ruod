class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int max_area = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(i, j, grid));
                }
            }
        }
        return max_area;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        int c = 0;
        if (i < 0 || j <0 || i==grid.size() || j==grid[0].size() || !grid[i][j]) return c;
        grid[i][j] = 0;
        c++;
        c += dfs(i + 1, j, grid);
        c += dfs(i - 1, j, grid);
        c += dfs(i, j + 1, grid);
        c += dfs(i, j - 1, grid);
        return c;
    }
};
