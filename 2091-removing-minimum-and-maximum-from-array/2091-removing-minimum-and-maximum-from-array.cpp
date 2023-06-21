class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();int minnum=nums[0], maxnum=nums[0] ,minindex=0, maxindex=0;
        int ans1=0,ans2=0;
        if(n==1)return 1;
        for(int i=0;i<n;i++){
            if(nums[i]<minnum){
                minnum=nums[i];
                minindex=i;
            }
            if(nums[i]>maxnum){
                maxnum=nums[i];
                maxindex=i;
            }
        }
      
    //   TYPE 1 (DELETION FROM RIGHT END)   n-min(minindex,maxindex);
    //   TYPE 2 (DELETION FROM LEFT END )   max(minindex,maxindex)+1;
    //   TYPE 3 (DELETING MAX INDEX FROM RIGHT AND MIN INDEX FROM LEFT) 
    //          n - max(minindex,maxindex) +    min(minindex,maxindex) + 1;

    // return min number of deletions after calcuationg deletions needed for each type

ans1=min( n-min(minindex,maxindex), max(minindex,maxindex)+1);

ans2= n - max(minindex,maxindex) + min(minindex,maxindex) + 1;

      return min(ans1,ans2);
    }
};