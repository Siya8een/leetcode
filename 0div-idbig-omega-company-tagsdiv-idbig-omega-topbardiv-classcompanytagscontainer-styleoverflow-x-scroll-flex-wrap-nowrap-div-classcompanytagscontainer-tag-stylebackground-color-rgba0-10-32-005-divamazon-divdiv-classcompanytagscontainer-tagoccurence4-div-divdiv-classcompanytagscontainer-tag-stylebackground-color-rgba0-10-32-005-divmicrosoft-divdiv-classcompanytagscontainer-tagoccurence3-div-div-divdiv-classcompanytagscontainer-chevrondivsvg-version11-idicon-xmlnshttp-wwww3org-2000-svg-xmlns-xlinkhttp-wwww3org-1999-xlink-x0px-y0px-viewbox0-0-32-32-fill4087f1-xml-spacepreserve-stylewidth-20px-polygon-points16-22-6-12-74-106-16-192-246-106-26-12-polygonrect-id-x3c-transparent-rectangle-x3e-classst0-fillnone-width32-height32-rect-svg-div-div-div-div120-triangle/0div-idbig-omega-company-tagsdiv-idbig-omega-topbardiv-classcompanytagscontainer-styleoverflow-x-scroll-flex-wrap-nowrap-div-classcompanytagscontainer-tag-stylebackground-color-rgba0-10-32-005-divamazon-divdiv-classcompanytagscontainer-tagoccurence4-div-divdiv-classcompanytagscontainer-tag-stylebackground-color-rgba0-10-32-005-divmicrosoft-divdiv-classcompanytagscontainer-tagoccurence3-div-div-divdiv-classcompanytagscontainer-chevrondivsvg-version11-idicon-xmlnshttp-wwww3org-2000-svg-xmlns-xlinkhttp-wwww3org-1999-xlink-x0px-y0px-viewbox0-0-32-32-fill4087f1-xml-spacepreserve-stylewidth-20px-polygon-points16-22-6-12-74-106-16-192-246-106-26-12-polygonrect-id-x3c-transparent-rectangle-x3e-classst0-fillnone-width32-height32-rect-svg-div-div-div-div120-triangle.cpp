class Solution {
public:
//     int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j) {
//         if (i == triangle.size() - 1) {
//             return triangle[i][j];
//         }
        
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int d = triangle[i][j] + solve(triangle, dp, i + 1, j);
//         int dg = triangle[i][j] + solve(triangle, dp, i + 1, j + 1);
//         dp[i][j] = min(d, dg);
        
//         return dp[i][j];
//     }

  int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
      vector < int > front ( n ,0 ), cur ( n,0);
      for ( int j =0 ; j < n ; j++){
           front [j]= triangle[n-1][j];
      }
      
      for ( int i =n-2;i >= 0 ;i--){
          for ( int j =i; j >= 0 ;j--){
              int d = triangle[i][j]+ front [j];
              int dg = triangle[i][j]+ front [j+1];
               cur[j] = min ( d,dg);
          }
          front = cur;
      }
      return front [0];
  }
};
