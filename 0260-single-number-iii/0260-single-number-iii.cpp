class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map <int,int> ans;
        vector <int > answer;
        for ( int i=0;i< nums.size();i++){
            ans[nums[i]]++;
        }
        for ( auto it: ans){
            if (it.second==1)
            {
                answer.push_back(it.first);
            }
            
        }
        return answer;
    }
};

;