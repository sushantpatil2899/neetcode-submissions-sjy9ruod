class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for (int c = 0; c < cols; c++) {
            dfs(0, c, pac, heights);
            dfs(rows -1, c, atl, heights);
        }

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pac, heights);
            dfs(r, cols-1, atl, heights);
        }

        vector<vector<int>> res;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) res.push_back({r, c});
            }
        }

        return res;
    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (int i = 0; i< 4; i++) {
            int row = r + dirs[i].first;
            int col = c + dirs[i].second;
            if (row >= 0 && col >= 0 && row < heights.size() && col <heights[0].size() && !ocean[row][col] && heights[r][c] <= heights[row][col]) dfs(row, col, ocean, heights);
        }
    }

};
