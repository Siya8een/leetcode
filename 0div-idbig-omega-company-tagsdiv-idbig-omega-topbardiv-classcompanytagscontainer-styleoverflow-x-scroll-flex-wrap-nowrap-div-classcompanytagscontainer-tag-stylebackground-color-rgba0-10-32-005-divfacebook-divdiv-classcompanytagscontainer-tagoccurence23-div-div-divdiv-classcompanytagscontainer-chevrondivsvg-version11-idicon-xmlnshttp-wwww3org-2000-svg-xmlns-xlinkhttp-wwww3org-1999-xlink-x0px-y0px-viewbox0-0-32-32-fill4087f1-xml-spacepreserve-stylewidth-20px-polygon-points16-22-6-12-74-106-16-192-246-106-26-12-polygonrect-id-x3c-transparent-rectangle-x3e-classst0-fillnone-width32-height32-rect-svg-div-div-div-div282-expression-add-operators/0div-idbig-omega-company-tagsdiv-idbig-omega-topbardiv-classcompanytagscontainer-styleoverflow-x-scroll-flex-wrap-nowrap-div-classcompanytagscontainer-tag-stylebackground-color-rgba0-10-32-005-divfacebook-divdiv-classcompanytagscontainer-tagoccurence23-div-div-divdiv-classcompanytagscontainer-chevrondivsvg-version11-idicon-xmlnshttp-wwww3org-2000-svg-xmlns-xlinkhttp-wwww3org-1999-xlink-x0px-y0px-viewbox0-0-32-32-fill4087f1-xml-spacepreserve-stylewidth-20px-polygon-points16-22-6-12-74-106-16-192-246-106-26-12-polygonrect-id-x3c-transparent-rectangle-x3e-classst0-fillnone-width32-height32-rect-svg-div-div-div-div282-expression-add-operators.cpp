#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(int index, string num, char lastOp, long long currentVal, long long prevNum, const string &expression, int target, vector<string> &result) {
        if (index == num.size()) {
            if (currentVal == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            string currentStr = num.substr(index, i - index + 1);
            long long currentNum = stoll(currentStr);

            if (to_string(currentNum).size() != currentStr.size()) {
                // Skip if leading zeros are present
                continue;
            }

            if (index == 0) {
                // The first number in the expression
                solve(i + 1, num, '+', currentNum, currentNum, currentStr, target, result);
            } else {
                solve(i + 1, num, '+', currentVal + currentNum, currentNum, expression + "+" + currentStr, target, result);
                solve(i + 1, num, '-', currentVal - currentNum, -currentNum, expression + "-" + currentStr, target, result);
                solve(i + 1, num, '*', currentVal - prevNum + prevNum * currentNum, prevNum * currentNum, expression + "*" + currentStr, target, result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) {
            return result;
        }

        string expression;
        solve(0, num, '+', 0, 0, expression, target, result);

        return result;
    }
};
