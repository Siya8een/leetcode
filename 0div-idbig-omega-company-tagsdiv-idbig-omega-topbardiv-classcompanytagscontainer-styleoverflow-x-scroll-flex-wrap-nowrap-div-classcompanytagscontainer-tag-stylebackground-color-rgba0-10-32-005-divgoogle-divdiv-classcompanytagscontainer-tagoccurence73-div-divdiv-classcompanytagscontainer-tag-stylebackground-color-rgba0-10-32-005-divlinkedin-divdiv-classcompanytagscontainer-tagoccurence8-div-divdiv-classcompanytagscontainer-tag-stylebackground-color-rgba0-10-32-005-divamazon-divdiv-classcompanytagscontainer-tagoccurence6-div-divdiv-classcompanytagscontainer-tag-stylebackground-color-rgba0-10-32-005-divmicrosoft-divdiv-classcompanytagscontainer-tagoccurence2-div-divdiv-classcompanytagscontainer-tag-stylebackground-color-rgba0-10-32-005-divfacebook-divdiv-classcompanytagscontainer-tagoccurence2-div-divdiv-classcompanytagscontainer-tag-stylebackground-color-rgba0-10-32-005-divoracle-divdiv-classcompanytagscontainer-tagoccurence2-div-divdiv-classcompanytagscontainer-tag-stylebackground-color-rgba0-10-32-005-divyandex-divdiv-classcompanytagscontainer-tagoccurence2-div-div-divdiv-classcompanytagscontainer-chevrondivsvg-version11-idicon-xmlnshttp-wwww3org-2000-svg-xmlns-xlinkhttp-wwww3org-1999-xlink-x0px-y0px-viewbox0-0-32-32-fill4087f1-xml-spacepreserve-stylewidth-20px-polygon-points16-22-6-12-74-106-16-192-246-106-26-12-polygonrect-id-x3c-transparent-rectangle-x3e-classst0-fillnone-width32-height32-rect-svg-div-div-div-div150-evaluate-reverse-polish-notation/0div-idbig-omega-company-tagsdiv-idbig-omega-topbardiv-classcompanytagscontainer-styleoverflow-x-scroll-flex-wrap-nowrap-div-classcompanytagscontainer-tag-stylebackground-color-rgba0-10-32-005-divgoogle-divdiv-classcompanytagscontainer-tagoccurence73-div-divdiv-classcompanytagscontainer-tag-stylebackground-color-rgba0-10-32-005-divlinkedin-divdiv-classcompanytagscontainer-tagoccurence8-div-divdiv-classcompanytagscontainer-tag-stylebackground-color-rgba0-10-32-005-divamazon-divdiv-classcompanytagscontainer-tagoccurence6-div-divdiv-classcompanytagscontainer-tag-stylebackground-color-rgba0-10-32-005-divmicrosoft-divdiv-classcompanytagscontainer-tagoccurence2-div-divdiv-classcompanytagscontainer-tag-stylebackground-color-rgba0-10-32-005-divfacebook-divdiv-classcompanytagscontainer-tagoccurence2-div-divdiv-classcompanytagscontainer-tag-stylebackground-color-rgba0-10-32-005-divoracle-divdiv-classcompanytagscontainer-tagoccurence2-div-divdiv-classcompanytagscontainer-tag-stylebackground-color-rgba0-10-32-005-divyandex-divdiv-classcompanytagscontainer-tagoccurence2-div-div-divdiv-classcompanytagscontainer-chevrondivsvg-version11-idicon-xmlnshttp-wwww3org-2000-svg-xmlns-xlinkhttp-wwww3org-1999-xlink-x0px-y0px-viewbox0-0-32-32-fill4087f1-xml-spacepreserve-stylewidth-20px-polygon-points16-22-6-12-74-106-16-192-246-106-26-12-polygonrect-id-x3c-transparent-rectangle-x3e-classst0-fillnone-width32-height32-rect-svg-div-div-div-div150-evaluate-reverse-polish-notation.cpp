class Solution {
public:
    bool ifchar(string a) {
        if (a == "+" || a == "-" || a == "*" || a == "/") {
            return true;
        }
        return false;
    }

    int perform(string& op, int x, int y) {
        if (op == "+") {
            return x + y;
        } else if (op == "-") {
            return y - x;  
        } else if (op == "*") {
            return x * y;
        } else if (op == "/") {
           
            if (x != 0) {
                return y / x;  
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
int ans =0;
    int evalRPN(vector<string>& tokens) {
        if ( tokens.size()==1){
            return stoi(tokens[0]);
        }
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (!ifchar(tokens[i])) {
                int z = stoi(tokens[i]);
                st.push(z);
            } 
            else {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
               ans = perform(tokens[i], x, y);
                cout << ans << endl;
                
                st.push(ans);
            }
        }
        return ans;
    }
};
