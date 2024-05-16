class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int mx = INT_MIN;
        for(auto &x:nums) 
        {
            mp[x]++;
            mx = max(mx, mp[x]);
        }

        vector<int>top;
        for(auto x:mp)
            if(x.second==mx) top.push_back(x.first);
        
        int ans = INT_MAX, n = nums.size();
        for(auto &x:top)
        {
            int idx1 = -1, idx2 = -1;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==x)
                {
                    idx1 = i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                if(nums[i]==x)
                {
                    idx2 = i;
                    break;
                }
            }
            ans = min(ans, (idx2 - idx1));
        }
        return ans+1;
    }
};