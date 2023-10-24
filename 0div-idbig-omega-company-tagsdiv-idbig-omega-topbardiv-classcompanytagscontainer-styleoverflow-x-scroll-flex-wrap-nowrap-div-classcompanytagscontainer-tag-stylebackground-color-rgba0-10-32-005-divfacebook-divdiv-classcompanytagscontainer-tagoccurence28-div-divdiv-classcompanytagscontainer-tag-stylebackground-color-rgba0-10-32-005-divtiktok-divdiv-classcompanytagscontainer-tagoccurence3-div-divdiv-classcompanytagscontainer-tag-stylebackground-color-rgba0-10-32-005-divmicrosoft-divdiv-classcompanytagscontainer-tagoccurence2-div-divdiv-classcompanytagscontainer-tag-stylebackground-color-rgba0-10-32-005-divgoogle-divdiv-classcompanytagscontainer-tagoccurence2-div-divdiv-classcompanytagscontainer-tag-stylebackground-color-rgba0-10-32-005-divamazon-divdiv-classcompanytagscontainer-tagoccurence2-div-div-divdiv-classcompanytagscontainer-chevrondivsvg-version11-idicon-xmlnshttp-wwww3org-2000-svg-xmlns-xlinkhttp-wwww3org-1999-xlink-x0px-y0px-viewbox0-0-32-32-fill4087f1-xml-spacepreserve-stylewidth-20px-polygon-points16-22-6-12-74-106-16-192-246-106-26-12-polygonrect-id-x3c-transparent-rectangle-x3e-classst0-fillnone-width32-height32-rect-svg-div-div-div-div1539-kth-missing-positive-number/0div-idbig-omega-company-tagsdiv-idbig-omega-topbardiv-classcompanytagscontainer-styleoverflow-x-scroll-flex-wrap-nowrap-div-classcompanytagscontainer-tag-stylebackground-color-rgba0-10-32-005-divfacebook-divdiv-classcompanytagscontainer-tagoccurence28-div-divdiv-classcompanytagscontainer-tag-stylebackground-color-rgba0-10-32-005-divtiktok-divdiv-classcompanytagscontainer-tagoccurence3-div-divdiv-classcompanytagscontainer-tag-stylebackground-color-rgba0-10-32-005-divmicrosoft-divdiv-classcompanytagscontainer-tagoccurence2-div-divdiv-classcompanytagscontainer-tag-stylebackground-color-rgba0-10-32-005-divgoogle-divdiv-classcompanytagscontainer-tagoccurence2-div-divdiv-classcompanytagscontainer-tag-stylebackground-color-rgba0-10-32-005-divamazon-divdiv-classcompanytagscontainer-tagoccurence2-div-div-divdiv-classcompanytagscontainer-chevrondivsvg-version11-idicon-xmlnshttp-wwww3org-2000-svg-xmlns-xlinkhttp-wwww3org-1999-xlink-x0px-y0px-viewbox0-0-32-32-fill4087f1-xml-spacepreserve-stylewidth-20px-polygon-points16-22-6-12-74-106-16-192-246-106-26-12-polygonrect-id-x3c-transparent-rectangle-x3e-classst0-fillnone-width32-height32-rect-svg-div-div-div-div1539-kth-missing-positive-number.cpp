class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 1; // Initialize the answer to 1
        int i = 0;   // Initialize the array index to 0

        while (k > 0) {
            if (i < arr.size() && arr[i] == ans) {
                        i++;
            } else {
                k--;
            }
            ans++; 
        }

        return ans - 1;
    }
};
