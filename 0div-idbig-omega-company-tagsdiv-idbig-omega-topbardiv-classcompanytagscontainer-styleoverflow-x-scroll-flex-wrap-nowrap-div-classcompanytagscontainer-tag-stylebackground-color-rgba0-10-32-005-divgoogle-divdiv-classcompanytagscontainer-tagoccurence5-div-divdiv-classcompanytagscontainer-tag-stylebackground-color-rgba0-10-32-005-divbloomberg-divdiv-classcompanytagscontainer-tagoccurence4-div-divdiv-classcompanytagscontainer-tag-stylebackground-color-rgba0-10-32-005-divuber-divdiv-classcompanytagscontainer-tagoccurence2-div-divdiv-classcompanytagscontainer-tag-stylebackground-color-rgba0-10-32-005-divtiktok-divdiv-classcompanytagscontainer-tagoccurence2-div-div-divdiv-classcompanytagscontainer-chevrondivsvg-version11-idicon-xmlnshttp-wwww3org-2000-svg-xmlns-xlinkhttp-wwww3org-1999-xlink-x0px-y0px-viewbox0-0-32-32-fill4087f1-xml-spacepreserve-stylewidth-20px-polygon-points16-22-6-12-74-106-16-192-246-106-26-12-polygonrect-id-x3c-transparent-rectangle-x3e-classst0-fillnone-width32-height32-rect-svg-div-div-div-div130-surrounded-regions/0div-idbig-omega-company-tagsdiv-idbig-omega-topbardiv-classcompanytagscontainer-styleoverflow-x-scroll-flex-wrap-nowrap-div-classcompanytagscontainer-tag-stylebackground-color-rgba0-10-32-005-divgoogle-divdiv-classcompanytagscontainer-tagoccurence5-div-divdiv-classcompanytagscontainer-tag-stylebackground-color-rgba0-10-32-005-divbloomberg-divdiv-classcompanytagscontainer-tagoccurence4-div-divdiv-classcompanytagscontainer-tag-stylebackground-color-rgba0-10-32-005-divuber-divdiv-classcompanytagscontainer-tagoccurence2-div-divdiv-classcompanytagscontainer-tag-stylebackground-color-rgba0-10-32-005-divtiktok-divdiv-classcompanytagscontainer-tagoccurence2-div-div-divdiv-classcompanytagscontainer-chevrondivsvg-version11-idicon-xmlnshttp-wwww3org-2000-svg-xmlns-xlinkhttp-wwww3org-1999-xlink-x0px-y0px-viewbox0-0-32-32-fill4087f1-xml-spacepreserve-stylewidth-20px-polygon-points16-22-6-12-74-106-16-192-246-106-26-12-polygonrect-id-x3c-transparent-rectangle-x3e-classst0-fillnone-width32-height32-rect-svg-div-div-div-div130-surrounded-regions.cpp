#include <vector>

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; // Handle the case where the board is empty.
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse the boundary
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, vis, board);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(n - 1, j, vis, board);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, board);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, board);
            }
        }

        // Flip the 'O's to 'X's and restore the 'E's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O' || vis[row][col]) {
            return;
        }

        vis[row][col] = 1;

        dfs(row - 1, col, vis, board);
        dfs(row + 1, col, vis, board);
        dfs(row, col - 1, vis, board);
        dfs(row, col + 1, vis, board);
    }
};
