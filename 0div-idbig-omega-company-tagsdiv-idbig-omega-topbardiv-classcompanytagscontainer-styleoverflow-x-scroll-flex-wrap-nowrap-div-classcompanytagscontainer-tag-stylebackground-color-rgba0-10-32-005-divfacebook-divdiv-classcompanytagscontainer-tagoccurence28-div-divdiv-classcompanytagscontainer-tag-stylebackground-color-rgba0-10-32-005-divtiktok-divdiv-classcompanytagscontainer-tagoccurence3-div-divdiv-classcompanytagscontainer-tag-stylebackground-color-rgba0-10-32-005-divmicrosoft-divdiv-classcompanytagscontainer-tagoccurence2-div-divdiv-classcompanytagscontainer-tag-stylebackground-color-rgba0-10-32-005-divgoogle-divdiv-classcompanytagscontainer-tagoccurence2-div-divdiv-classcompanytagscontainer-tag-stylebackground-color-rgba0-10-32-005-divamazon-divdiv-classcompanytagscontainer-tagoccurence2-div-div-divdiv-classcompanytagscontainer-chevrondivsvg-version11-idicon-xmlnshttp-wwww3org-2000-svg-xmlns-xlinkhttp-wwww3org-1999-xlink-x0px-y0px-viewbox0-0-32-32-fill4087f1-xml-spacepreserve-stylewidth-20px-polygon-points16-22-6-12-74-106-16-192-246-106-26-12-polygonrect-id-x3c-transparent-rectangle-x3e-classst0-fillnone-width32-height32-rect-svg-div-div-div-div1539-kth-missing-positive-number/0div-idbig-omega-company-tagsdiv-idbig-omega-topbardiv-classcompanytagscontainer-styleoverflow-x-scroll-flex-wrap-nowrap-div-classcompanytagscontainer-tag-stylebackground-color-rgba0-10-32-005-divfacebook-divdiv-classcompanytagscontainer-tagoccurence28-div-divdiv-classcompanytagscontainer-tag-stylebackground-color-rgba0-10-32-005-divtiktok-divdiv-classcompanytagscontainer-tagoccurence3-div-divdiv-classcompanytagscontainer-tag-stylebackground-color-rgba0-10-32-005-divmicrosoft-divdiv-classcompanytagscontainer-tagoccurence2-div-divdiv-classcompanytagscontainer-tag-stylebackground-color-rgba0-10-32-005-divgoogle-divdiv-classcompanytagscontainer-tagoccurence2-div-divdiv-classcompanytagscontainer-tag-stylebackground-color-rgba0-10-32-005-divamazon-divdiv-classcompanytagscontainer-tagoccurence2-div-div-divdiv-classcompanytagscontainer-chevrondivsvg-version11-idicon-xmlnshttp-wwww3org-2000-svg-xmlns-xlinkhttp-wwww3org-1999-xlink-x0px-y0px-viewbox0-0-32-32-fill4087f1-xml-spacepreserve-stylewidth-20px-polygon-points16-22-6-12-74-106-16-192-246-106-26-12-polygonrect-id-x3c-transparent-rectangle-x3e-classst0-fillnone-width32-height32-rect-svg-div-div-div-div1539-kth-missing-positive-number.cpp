class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 1; // Initialize the answer to 1
        int i = 0;   // Initialize the array index to 0

        while (k > 0) {
            if (i < arr.size() && arr[i] == ans) {
                // If the current number exists in the array, move to the next number in the array.
                i++;
            } else {
                // If the current number is missing, decrement k.
                k--;
            }
            ans++; // Move to the next expected positive integer.
        }

        return ans - 1; // Return ans - 1 because ans is already incremented for the k-th missing integer.
    }
};
