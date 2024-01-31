class Solution {
public:
   int solveCommonSubsequence(int index1, int index2, string &s1, string &s2, vector<vector<int>> &memo) {
        if (index1 < 0 || index2 < 0) {
            return 0;
        }

        if (memo[index1][index2] != -1) {
            return memo[index1][index2];
        }

        int a = 0, b = 0;

        if (s1[index1] == s2[index2]) {
            a = 1 + solveCommonSubsequence(index1 - 1, index2 - 1, s1, s2, memo);
        } else {
            a = max(solveCommonSubsequence(index1, index2 - 1, s1, s2, memo),
                    solveCommonSubsequence(index1 - 1, index2, s1, s2, memo));
        }

        memo[index1][index2] = a;
        return a;
    }
    int minInsertions(string s) {
       // find the longest pallindrom length 
         string s1 = s ;
             reverse( s. begin(), s.end()); 
         string s2 = s ;
        int index1 = s.size() ;
        int index2 = s.size() ;
            int n = s1.length();
         vector<vector<int>> memo(n, vector<int>(n, -1));
    int l = solveCommonSubsequence (index1-1 , index2-1, s1, s2, memo);
        return ( s.size() - l);
    }
};


   
   