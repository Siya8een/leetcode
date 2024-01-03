#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // If the word is found
        if (k == word.size()) {
            return true;
        }

        // Check if the current position is out of bounds or the character doesn't match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }

        // Mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '*';

        // Explore in all four directions
        bool found = solve(board, word, i + 1, j, k + 1) ||
                     solve(board, word, i - 1, j, k + 1) ||
                     solve(board, word, i, j + 1, k + 1) ||
                     solve(board, word, i, j - 1, k + 1);

        // Restore the original value of the cell
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
