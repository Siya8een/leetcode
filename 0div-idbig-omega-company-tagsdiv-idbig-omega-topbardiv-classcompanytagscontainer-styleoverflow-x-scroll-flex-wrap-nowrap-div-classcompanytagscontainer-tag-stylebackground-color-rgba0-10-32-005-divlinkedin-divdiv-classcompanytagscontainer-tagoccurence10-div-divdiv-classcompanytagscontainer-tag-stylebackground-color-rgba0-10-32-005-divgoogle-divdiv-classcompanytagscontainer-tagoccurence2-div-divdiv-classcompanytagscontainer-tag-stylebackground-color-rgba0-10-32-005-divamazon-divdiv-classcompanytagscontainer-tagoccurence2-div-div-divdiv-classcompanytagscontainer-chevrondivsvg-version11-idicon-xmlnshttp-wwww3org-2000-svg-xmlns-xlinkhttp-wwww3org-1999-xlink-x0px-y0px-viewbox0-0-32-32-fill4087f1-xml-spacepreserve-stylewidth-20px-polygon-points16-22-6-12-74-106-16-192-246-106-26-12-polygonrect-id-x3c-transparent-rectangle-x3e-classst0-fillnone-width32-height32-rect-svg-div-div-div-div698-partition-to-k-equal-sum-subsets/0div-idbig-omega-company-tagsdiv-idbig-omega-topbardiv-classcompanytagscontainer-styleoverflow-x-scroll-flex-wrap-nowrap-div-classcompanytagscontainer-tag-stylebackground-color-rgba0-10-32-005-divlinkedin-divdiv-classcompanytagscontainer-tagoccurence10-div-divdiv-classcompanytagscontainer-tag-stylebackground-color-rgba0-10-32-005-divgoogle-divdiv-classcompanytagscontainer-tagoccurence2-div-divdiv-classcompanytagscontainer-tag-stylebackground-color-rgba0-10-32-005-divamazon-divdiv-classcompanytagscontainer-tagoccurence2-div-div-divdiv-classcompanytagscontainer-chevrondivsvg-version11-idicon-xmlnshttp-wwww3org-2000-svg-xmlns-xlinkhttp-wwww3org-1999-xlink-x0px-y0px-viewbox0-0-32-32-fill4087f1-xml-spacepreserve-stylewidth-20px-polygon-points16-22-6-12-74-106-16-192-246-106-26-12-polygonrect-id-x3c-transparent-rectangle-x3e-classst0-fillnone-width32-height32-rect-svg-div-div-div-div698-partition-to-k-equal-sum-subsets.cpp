class Solution {
public:
    int n;
    bool backtrack(vector<int>& nums,vector<bool>& vis,int i,int curr,int& tar,int k){
        if(k==1)return true;
        if(curr==tar){
            return backtrack(nums,vis,0,0,tar,k-1);
        }
        for(int j=i+1;j<n;j++){
            if(vis[j] || curr+nums[j]>tar)continue;
            vis[j]=true;
            if(backtrack(nums,vis,j,curr+nums[j],tar,k))
                return true;
            vis[j]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(n<k || sum%k)return false;
        int tar=sum/k;
        vector<bool> vis(n,false);
        return backtrack(nums,vis,0,0,tar,k);
    }
};