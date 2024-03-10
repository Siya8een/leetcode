class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector < int> ans ;
        unordered_map <int ,int > mpp;
        for ( int i =0; i < nums1.size(); i++){
            mpp[nums1[i]]++;
        }
        unordered_set < int > ansNo;
        for ( int i =0; i < nums2.size();i++){
            if (mpp.find(nums2[i])!= mpp.end()){
                ansNo.insert(nums2[i]);
            }
        }
        for ( auto it : ansNo){
            ans.push_back(it);
        }
        return ans;
    }
};