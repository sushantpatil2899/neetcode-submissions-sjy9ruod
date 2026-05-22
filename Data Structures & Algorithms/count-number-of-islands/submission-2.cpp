class Solution {
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int c = 0;
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    c++;
                }
            }
        }

        return c;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        if (validEdge(i-1, j) && grid[i-1][j]=='1') dfs(i-1, j, grid);
        if (validEdge(i+1, j) && grid[i+1][j]=='1') dfs(i+1, j, grid); 
        if (validEdge(i, j-1) && grid[i][j-1]=='1') dfs(i, j-1, grid); 
        if (validEdge(i, j+1) && grid[i][j+1]=='1') dfs(i, j+1, grid); 
    }

    bool validEdge(int i, int j) {
        return (i >= 0 && i< m && j >=0 && j<n);
    }
};
