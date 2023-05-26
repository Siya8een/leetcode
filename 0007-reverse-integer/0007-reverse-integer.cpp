class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;
            // Check for potential overflow before updating the answer
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 8))
                return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
                return 0;
else{
            ans = ans * 10 + digit;
            x = x / 10;}
        }

        return ans;
    }
};
