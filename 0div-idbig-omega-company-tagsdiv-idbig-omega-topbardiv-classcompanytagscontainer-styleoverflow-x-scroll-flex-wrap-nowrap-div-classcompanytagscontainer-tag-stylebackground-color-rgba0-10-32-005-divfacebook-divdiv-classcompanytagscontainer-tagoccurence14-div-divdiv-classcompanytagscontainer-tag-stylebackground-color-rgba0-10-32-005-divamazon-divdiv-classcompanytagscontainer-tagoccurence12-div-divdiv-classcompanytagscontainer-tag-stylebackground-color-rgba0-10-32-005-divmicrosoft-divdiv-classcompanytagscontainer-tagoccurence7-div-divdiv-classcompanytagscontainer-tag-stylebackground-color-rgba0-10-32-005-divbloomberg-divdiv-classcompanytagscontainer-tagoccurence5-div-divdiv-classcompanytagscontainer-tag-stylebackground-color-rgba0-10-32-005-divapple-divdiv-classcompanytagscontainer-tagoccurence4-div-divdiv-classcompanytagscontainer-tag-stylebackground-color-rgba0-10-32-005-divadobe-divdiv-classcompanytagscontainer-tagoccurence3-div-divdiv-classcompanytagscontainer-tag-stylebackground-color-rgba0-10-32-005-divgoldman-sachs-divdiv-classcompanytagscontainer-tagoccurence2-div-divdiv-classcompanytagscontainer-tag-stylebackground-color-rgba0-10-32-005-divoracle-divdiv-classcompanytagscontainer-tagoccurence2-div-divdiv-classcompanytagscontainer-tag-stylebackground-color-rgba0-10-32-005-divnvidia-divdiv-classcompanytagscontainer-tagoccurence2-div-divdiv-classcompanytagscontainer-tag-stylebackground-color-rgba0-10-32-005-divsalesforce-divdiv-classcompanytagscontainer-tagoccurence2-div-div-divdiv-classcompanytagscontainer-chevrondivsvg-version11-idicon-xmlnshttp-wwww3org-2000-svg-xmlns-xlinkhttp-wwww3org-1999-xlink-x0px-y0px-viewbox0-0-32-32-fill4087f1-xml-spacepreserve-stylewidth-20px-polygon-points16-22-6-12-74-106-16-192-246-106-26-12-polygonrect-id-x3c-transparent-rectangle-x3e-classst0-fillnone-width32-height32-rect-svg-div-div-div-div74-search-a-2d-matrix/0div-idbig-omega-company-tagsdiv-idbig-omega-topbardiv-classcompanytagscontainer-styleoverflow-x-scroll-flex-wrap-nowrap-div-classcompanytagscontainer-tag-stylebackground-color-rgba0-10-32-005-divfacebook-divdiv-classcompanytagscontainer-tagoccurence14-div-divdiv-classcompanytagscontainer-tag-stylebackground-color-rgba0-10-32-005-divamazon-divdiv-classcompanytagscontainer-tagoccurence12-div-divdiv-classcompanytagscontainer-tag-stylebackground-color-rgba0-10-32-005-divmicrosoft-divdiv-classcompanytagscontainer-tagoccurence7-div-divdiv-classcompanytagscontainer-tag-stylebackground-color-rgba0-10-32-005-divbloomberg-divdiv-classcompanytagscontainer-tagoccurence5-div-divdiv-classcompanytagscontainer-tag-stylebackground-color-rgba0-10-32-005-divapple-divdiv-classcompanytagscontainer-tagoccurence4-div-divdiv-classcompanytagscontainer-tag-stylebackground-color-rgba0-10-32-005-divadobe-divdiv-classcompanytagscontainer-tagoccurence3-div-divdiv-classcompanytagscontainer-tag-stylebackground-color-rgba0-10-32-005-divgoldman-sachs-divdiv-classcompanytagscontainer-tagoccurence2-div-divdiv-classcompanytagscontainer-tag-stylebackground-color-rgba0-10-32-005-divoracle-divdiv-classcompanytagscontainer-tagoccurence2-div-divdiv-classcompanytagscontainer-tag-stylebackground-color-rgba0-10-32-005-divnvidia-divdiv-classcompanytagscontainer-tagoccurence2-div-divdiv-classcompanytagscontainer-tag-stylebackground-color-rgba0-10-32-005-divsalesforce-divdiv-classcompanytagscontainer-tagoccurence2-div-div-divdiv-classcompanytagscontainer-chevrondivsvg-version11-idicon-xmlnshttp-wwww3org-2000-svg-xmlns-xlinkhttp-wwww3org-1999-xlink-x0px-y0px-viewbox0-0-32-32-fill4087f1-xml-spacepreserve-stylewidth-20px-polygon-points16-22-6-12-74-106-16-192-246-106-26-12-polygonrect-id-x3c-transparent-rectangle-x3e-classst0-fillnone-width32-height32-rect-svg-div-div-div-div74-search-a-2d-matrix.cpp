class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0; 
        int j = m - 1; // Start from the top-right corner

        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                i++; // Move down
            } else {
                j--; // Move left
            }
        }
        return false;
    }
};
