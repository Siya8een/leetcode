class Solution {
public:
    int count ( int i, int j,vector <vector<int>> & dp, int m,int n )
    {
        if ( i==n-1 || j ==m-1 ){
            
            return 1;
        }
        else if ( i>= n || j>= m){
            
            return 0;
            
        }
        else if ( dp[i][j] != -1){
            
            return dp[i][j];
            
        }
        
        else {
            return dp[i][j] =( count(i+1, j,dp, m,n) + count ( i, j+1, dp,m,n) );
        }
    }
        
        int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return count ( i,  j, dp, m,n);
    }
};