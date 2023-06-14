class Solution {
public:
    bool isThree(int n) {
        if (n < 4)
            return false;

        int sqrtN = sqrt(n);

        // Check if n is a perfect square
        if (sqrtN * sqrtN != n)
            return false;

        // Check if the square root of n is a prime number
        for (int i = 2; i * i <= sqrtN; i++) {
            if (sqrtN % i == 0)
                return false;
        }

        return true;
    }
};
