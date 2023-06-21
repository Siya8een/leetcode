class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n = s.length();
        int i=0;
        while ( i< s.length()){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;  // No opening bracket to match with
                }
                
               char topElement = st.top();
                st.pop();
                
                if (!matches(topElement, s[i])) {
                    return false;  // Mismatched opening and closing brackets
                }
            }
            
            i++;
        }
        
        return st.empty();  // Check if there are any unclosed opening brackets left
    }
    
private:
    bool matches(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};