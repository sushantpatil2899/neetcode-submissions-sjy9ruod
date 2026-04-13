class Solution {
private:
    set<pair<int, int>> find(vector<vector<int>>& board) {
        set<pair<int, int>> crushedCandies;
        int m = board.size();
        int n = board[0].size();

        for (int r = 1; r <m-1; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 0) continue;
                if ((board[r][c] == board[r-1][c]) 
                && (board[r][c] == board[r+1][c])) {
                    crushedCandies.insert({r, c});
                    crushedCandies.insert({r-1, c});
                    crushedCandies.insert({r+1, c});
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 1; c < n-1; c++) {
                if (board[r][c] == 0) continue;
                if ((board[r][c] == board[r][c-1]) 
                && (board[r][c] == board[r][c+1])) {
                    crushedCandies.insert({r, c});
                    crushedCandies.insert({r, c-1});
                    crushedCandies.insert({r, c+1});
                }
            }
        }
        return crushedCandies;
    }

    void crush(vector<vector<int>>& board, set<pair<int, int>>& crushedCandies) {
        for (const auto& p: crushedCandies) {
            board[p.first][p.second] = 0;
        }
    }

    void drop(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int c = 0; c < n; c++) {
            int lowestZero = -1;

            for (int r = m - 1; r>=0; r--) {
                if (board[r][c] == 0) lowestZero = max(lowestZero, r);
                else if (lowestZero>=0) {
                    int temp = board[r][c];
                    board[r][c] = board[lowestZero][c];
                    board[lowestZero][c] = temp;
                    lowestZero--;
                }
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        set<pair<int, int>> crushedCandies = find(board);
        while (!crushedCandies.empty()) {
            crush(board, crushedCandies);
            drop(board);
            crushedCandies = find(board);
        }
        return board;
    }
};
