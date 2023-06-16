class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        
        // Count the number of zeros
        for (i = 0; i < n; i++) {
            if (arr[i] == 0)
                j++;
        }
        
        // Adjust the size of the array to accommodate the additional zeros
        arr.resize(n + j);
        
        // Duplicate zeros in the modified array
        i = n - 1;
        j = n + j - 1;
        while (i >= 0) {
            if (arr[i] == 0) {
                arr[j--] = 0;
                arr[j--] = 0;
            } else {
                arr[j--] = arr[i];
            }
            i--;
        }
        
        // Remove excess elements beyond the original length
        arr.resize(n);
    }
};
