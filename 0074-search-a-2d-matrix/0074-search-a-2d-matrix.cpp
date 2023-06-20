class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        double right = m * n - 1;
        
        while (left <= right) {
            int mid = (right + (left - right) / 2);
            
            if (target == matrix[mid / n][mid % n]) {
                return true;
            } else if (target < matrix[mid / n][mid % n]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return false;
    }
};
