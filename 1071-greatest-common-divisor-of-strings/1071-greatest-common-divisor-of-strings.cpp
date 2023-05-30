class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            // If str1 + str2 is not equal to str2 + str1,
            // there is no common divisor string.
            return "";
        }
        
        // Calculate the GCD length using Euclidean algorithm
        int len1 = str1.length();
        int len2 = str2.length();
        int gcdLen = gcd(len1, len2);
        
        // Return the substring from str1 with length gcdLen
        return str1.substr(0, gcdLen);
    }
    
private:
    int gcd(int a, int b) {
        // Euclidean algorithm to find GCD
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
};
