class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;

        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                if (grid[r][c]) {
                    max_area = max(max_area, dfs(grid, r,c));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]==0) {
            return 0;
        }
        int count = 1;
        grid[r][c] = 0;
        count = count + dfs(grid, r+1, c);
        count = count + dfs(grid, r-1, c);
        count = count + dfs(grid, r, c+1);
        count = count + dfs(grid, r, c-1);
        return count;
    }
};