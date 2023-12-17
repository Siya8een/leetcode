#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> finalPrices(n, 0);
        std::stack<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && prices[i] <= prices[stack.top()]) {
                finalPrices[stack.top()] = prices[stack.top()] - prices[i];
                stack.pop();
            }
            stack.push(i);
        }

        while (!stack.empty()) {
            finalPrices[stack.top()] = prices[stack.top()];
            stack.pop();
        }

        return finalPrices;
    }
};
