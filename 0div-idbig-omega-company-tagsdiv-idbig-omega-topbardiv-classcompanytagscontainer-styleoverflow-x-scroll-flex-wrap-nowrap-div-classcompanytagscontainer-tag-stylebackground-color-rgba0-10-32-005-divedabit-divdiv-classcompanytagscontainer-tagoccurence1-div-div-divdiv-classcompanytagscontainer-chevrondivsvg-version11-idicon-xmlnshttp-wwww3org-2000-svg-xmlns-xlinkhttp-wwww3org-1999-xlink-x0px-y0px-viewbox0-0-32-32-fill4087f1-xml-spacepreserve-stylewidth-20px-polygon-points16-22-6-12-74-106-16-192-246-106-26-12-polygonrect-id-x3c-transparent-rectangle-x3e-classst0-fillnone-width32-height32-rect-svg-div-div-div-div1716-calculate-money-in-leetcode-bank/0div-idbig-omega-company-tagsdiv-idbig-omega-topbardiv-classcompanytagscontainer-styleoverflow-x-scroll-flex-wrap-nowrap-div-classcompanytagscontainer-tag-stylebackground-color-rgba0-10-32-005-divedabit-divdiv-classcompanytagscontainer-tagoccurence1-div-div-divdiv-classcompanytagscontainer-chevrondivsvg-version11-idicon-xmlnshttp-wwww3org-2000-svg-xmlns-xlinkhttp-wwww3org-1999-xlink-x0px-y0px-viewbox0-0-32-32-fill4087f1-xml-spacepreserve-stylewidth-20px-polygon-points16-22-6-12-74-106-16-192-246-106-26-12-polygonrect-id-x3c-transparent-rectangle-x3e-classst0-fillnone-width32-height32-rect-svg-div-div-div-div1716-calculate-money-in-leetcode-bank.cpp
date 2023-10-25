class Solution {
public:
    int totalMoney(int n) {

        int complete_weeks = n / 7 , inc_weeks = n % 7 ;

        // 28 + 35 + 42 + .. xterms 

        int ans = ((complete_weeks) * ( 2 * 28 + ( complete_weeks - 1 ) * 7 ))/2;

        // complete weeks + 1 + ... + (complete_weeks + inc_weeks) [ terms ->  inc_weeks ] 

        ans +=  ((inc_weeks) * ( 2 * (complete_weeks + 1) + ( inc_weeks - 1 ) * 1 ))/2;

        return ans;

    }
};