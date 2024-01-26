class Solution {
public:
    int countPaths(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>>& memo) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1; // Out of bounds, count as a path
        }
        if (maxMove == 0) {
            return 0; // No more moves left, no path
        }
        if (memo[i][j][maxMove] != -1) {
            return memo[i][j][maxMove];
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        long long paths = 0;

        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            paths += countPaths(m, n, maxMove - 1, ni, nj, memo);
            paths %= 1000000007;
        }

        memo[i][j][maxMove] = paths;
        return paths;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return countPaths(m, n, maxMove, startRow, startColumn, memo);
    }
};
