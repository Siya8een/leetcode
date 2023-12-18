#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        const int MOD = 1e9 + 7; // Modulo 10^9 + 7
        int n = arr.size();
        std::vector<int> left(n), right(n);
        
        std::stack<int> st;

        // Calculate the count of elements to the left of each element that are greater than the element
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!st.empty() && arr[st.top()] > arr[i]) {
                count = (count + left[st.top()]) % MOD;
                st.pop();
            }
            left[i] = count;
            st.push(i);
        }

        while (!st.empty()) st.pop(); // Clear the stack

        // Calculate the count of elements to the right of each element that are greater than or equal to the element
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                count = (count + right[st.top()]) % MOD;
                st.pop();
            }
            right[i] = count;
            st.push(i);
        }

        long long ans = 0;

        // Calculate the contribution of each element to the final result
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)(left[i] * right[i] % MOD) * arr[i]) % MOD;
        }

        return static_cast<int>(ans);
    }
};
