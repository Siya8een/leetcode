class Solution {
public:
    int solve(int index1, int index2, const string& text1, const string& text2, vector<vector<int>>& dp) {
        if (index1 ==0 || index2 == 0) {
            return 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        if (text1[index1-1] == text2[index2-1]) {
            return dp[index1][index2] = 1 + solve(index1 - 1, index2 - 1, text1, text2, dp);
        }

        dp[index1][index2] = max(solve(index1 - 1, index2, text1, text2, dp), solve(index1, index2 - 1, text1, text2, dp));
        return dp[index1][index2];
    }
    int minDistance(string word1, string word2) {
        // finding the  common subsequence 
         int index1 = word1.length();
        int index2 = word2.length();
        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));
        // TO PERFFORM TABULATION WE NEED TO GIVE SHIFTEDE INDEX ;  F( 0)= i = i-1  and  //F(j) = j =j-1;
     
        int l= solve ( index1, index2, word1, word2, dp);
        int ans = (word1.length() + word2.length())-(2*l);
        return ans ;
    }
};