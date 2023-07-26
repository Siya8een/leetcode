class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
        //vector<int> dp(n);
      int  prev1 = cost[0];
       int prev2 = cost[1];
        if (n==0){
            return prev1;
        }
        if (n==1){
            return prev2;
        }
        int ans=0;
          for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2); //   reach the current step.
            prev1 = prev2; 
            prev2 = curr; 
        }
        
        return min(prev1, prev2); 
    }
};