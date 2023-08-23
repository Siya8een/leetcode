class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false; // If the lengths are different, rotation is not possible
        }
        
        string doubleS = s + s; // Concatenate s with itself
        
        return doubleS.find(goal) != string::npos; // Check if goal is a substring of doubleS
    }
};
