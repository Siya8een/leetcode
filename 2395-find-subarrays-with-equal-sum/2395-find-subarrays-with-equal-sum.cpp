class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector <int> ans;
        for (int i=0;i < nums.size()-1;i++){
            int a = nums[i]+nums[i+1];
            ans.push_back(a);
        }
        unordered_map<int,int> a;
        // find if it has any same element
        for ( int i=0;i<ans.size();i++){
            a[ans[i]]++;
            if (a[ans[i]]==2){
                return true;
                break;
            }
        }
        return false;
    }
};