class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // dq to keep check of elements 
        deque <int > dq;
        // to store answer
        vector <int> ans;
        
      for( int i=0; i< nums.size(); i++){
            
            
            
            //to maintain window size
            if (!dq.empty() && dq.front() == i - k ){
                dq.pop_front();
            }
            // to maintain decreasing order
           while (!dq.empty() && nums[dq.back()]<= nums[i]){
                dq.pop_back();
            }
            
            // push back simply
            dq.push_back(i);
            if ( i>= k-1)
            ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};