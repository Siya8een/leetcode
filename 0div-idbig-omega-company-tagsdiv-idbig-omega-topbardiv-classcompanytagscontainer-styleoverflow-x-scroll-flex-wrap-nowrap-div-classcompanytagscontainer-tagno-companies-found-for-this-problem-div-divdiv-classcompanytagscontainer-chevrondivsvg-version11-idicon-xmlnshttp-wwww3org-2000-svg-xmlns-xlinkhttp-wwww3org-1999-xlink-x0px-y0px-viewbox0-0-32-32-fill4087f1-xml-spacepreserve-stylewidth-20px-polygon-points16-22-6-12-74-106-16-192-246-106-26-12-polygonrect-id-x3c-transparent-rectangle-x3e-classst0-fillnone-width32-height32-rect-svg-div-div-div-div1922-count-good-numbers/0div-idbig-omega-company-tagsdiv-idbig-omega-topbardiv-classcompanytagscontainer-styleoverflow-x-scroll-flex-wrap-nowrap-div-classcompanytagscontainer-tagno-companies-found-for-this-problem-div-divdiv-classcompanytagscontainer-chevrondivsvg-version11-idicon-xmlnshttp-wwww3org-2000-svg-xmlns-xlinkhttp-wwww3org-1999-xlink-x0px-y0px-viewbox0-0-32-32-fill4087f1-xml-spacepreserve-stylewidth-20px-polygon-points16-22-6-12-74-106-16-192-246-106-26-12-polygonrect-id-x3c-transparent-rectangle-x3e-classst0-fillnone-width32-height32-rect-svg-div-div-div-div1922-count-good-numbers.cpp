// class Solution {
// public:
//     int mod = 1000000007;
//     int countGoodNumbers(long long n) {
        
//      long long ans=1;
        
//         for ( int i=0;i< n;i++){
//             if (i%2 == 0){
//                 ans = (ans * 5)% mod;
//             }
//             else {
//                 ans = (ans * 4)% mod;
//             }
//         }
//         ans = ans % mod;
//         return (int)ans;
//     }
// };
class Solution {
public:
    long long powerr(long long num, long long k) {
       
        long long ans = 1;
        while (k!=0) {
            if (k % 2) {
                ans = (ans * num) % (1000000007);  // Calculate modulo 10^9 + 7 here
                k = k - 1;
            } else {
                num = (num * num) % (1000000007);  // Calculate modulo 10^9 + 7 here
                k = k / 2;
            }
        }
        return ans;
        cout<<ans << endl;

    }

    int countGoodNumbers(long long n) {
        
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        int ans;
        ans = (int)((powerr(5, even) * powerr(4, odd)) % (1000000007));  // Calculate modulo 10^9 + 7 here
        return ans;
    }
};