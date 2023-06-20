class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        int y = matrix.size(), i = 0, j = matrix[0].size() - 1;
        while (i < y && ~j) {
            int cell = matrix[i][j];
            if (cell == target) return true;
            else if (cell > target) j--;
            else i++;
        }
        return false;
    }
};
   