class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false; // If the lengths are different, rotation is not possible
        }
        
        string d = s + s; // Concatenate s with itself
        
        return d.find(goal) != string::npos; 
    }
};
