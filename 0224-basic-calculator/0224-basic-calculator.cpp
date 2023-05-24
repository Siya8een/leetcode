#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        int operand = 0;
        int result = 0;
        int sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                operand = operand * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * operand;
                operand = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                operands.push(result);
                operators.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * operand;
                operand = 0;
                result *= operators.top();
                operators.pop();
                result += operands.top();
                operands.pop();
            }
        }

        return result + (sign * operand);
    }
};

