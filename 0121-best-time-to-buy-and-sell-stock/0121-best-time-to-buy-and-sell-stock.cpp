// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int m = INT_MIN;
//         int l = INT_MAX;
        
//         for (int i = n - 1; i >= 0; i--) {
//             m = max(m, prices[i]);
//         }
        
//         if (prices[0] > l) {
//             for (int i = 0; i < n; i++) {
//                 l = min(l, prices[i]);
//             }
            
//             return m - l;
//         } else {
//             return 0;
//         }
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
};

