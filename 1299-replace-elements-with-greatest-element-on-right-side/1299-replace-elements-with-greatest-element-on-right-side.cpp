class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector <int > ans;
        int maxx = arr [arr.size()-1];
         int n = arr.size();
         ans .push_back ( maxx);
        for (  int i = n-2;i>= 0; i--){
            maxx = max( maxx, arr [i+1]);
           ans. push_back ( maxx);
        }
        reverse( ans .begin(), ans.end());
       ans[ans.size()-1]= -1;
        return ans;
    }
};