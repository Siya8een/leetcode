class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string word, ans = "";
        
        while(str >> word)//to find word in a string
           ans = word + " " + ans;
        
        
        ans.pop_back();// removes the extra space at the end of the reversed string, as the last iteration of the loop added a space after the last word.
        
        return ans;
    }
};