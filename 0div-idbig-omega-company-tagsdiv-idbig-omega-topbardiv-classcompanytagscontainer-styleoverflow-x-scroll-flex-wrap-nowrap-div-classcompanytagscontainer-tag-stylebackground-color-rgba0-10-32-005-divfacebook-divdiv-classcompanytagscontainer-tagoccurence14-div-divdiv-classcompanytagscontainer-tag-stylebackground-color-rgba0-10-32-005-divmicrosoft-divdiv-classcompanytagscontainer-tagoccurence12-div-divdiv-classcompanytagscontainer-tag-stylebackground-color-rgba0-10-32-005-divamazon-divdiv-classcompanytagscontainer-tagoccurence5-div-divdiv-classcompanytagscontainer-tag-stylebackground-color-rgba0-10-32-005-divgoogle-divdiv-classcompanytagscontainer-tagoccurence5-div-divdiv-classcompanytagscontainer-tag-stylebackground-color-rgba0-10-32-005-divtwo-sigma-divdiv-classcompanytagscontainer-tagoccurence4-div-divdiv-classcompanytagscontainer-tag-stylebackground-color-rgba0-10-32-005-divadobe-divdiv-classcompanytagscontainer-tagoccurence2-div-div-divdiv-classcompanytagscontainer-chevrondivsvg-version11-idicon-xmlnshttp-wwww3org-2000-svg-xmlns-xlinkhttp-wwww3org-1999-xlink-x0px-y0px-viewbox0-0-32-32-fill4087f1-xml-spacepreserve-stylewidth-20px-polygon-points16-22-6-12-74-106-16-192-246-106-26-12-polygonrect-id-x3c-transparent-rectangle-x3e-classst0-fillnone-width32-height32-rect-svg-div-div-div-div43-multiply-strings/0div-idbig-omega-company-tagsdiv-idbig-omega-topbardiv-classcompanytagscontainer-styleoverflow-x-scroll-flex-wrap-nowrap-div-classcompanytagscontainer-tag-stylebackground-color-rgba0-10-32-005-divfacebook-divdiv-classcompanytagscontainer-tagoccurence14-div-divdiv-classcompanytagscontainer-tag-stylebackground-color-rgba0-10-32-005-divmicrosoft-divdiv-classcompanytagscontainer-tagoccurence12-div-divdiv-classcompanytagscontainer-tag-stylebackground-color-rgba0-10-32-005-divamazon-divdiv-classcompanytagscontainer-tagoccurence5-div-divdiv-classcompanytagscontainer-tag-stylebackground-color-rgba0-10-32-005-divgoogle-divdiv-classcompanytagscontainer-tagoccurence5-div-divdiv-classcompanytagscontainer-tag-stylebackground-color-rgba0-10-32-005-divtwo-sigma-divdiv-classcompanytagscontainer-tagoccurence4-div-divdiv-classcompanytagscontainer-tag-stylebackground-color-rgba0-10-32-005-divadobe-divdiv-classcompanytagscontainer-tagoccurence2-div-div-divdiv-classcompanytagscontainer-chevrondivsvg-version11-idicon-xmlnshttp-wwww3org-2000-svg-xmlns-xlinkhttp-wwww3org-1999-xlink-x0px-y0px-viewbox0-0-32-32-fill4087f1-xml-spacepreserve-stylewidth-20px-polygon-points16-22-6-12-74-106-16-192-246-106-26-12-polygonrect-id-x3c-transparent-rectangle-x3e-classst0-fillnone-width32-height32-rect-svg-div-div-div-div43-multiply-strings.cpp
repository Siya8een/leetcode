
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int n = num1.size();
        int m = num2.size();

        // Result vector to store the product
        std::vector<int> result(n + m, 0);

        // Multiply each digit and add to the result vector
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        // Convert result vector to string
        std::string resultString;
        for (int digit : result) {
            if (!(resultString.empty() && digit == 0)) {
                resultString.push_back(digit + '0');
            }
        }

        // Handle case where result is zero
        return resultString.empty() ? "0" : resultString;
    }
};