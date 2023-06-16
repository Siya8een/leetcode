class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;// lowest price
        int op = 0;// max profit track
        int pist = 0;//the profit that can be obtained if the stock is sold at the current price.
        
        for(int i = 0; i < prices.size(); i++){
            //if(prices[i] < lsf){
                lsf =min(lsf,prices[i]) ;
            //}
            pist = prices[i] - lsf;
            op = max ( op, pist);
        }
        return op;
    }
};