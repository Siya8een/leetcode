#include <stack>
#include <string>

class Solution {
private:
    bool matches(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                
                char top_element = st.top();
                st.pop();
                
                if (!matches(top_element, s[i])) {
                    return false;
                }
            }
            
            i++;
        }
        
        return st.empty();
    }
};
