class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count1=INT_MIN;
        int count =0;
        for ( int i=0;i< nums.size();i++){
            
             if ( nums[i]==1){
                 count++;
           
             }

            else {
                count =0;
            }
             count1= max ( count,count1);
        }
        return count1;
    }
};