class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> countPaths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        return uniquePathsWithObstacles(0, 0, countPaths, obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size());
    }

    int uniquePathsWithObstacles(int r, int c, vector<vector<int>>& countPaths, vector<vector<int>>& obstacleGrid, int rows, int cols) {
        if (r==rows || c==cols || obstacleGrid[r][c]) return 0;
        if (countPaths[r][c]>-1) return countPaths[r][c];
        if (r==rows-1 && c==cols-1) return 1;

        countPaths[r][c] = uniquePathsWithObstacles(r+1, c, countPaths, obstacleGrid, rows, cols) + uniquePathsWithObstacles(r, c+1, countPaths, obstacleGrid, rows, cols);
        return countPaths[r][c];
    }
};