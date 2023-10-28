// class Solution {
// public:
//     int call ( vector<int>& nums, int k){
//         int i =0 ; 
//          int j =0; 
//         int count =0;
//          map <int , int > m;
//         while ( i < nums.size()){
//             m[nums[i]]++;
//              while (m.size()>k){
//                   auto it = m.find ( nums[i]);
//               (   it -> second )--;
//                  if ( it -> second  ==0){
//                      m.erase(it);
//                      j++;
//                  }
//                   count = count +( i -j +1);
//                  i++;
//              }
//         }
        
//         return count;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return call( nums, k)-call( nums, k-1);
            
//     }
// };
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        int left = 0;
        int distinctCount = 0;
        int result = 0;

        for (int right = 0; right < n; right++) {
            if (count[nums[right]] == 0) {
                distinctCount++;
            }
            count[nums[right]]++;

            while (distinctCount > k) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    distinctCount--;
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }
};
