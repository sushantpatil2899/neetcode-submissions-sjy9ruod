class Solution {
public:

    int countPathsRecursive(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& visit) {
        int rows = grid.size();
        int col = grid[0].size();

        if (min(r,c) < 0 || r ==rows || c==col || grid[r][c]==1 || visit[r][c]==1) return 0;
        if (r == rows-1 && c==col-1) return 1;
        visit[r][c] = 1;
        int count = 0;
        count = count + countPathsRecursive(grid, r+1, c, visit);
        count = count + countPathsRecursive(grid, r-1, c, visit);
        count = count + countPathsRecursive(grid, r, c+1, visit);
        count = count + countPathsRecursive(grid, r, c-1, visit);
        visit[r][c] = 0;
        return count;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        return countPathsRecursive(grid, 0, 0, visit);
    }
};
