class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        // declare a min heap
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            
            if(diff <= 0)    // next building has smaller height
            {
                continue;
            }
            else             // next building has greater height
            {
                pq.push(diff);
                
                if(pq.size() > ladders)   // in this case we have to use bricks
                {
                    bricks -= pq.top();
                    
                    pq.pop();
                }
                
                if(bricks < 0)     // if bricks becomes less than 0 then further we can't reach
                {
                    return i;
                }
            }
        }
        
        return n - 1;
    }
};