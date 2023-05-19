
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int i,c1=0,c2=0,c3=0;
       for(i=0;i<nums.size();i++)
       {
           switch(nums[i])
           {
               case 0:c1++;break;
               case 1:c2++;break;
               case 2:c3++;break;
           }
       }
        i = 0;
 
    // Store all the 0s in the beginning
    while (c1 > 0) {
        nums[i++] = 0;
        c1--;
    }
 
    // Then all the 1s
    while (c2 > 0) {
        nums[i++] = 1;
        c2--;
    }
 
    // Finally all the 2s
    while (c3 > 0) {
        nums[i++] = 2;
        c3--;
    }
}
};