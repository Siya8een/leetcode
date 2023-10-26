class Solution {
public:
long long minimalKSum(vector<int>& nums, int k) {
    
    long long res = 0, cur = 1;
    
    nums.push_back(INT_MAX);

    sort(begin(nums), end(nums));

    for (int i = 0; k > 0 && i < nums.size(); ++i) 
    {
        int gap = max(0, min(k, nums[i] - (int)cur));
        res += (cur + gap) * (cur + gap - 1) / 2 - cur * (cur - 1) / 2;
        
        k -= gap;

        cur = (long long)nums[i] + 1;
    }
    return res;
}
};