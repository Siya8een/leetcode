class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = *max_element(piles.begin(), piles.end()); // Find the maximum pile size
        
        int start = 1;
        int end = maxPile;
        int minSpeed = INT_MAX;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long hours = 0; // Use long long to handle larger values
            
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + mid - 1LL) / mid; // Use 1LL to ensure long long arithmetic
            }
            
            if (hours <= h) {
                minSpeed = min(minSpeed, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return minSpeed;
    }
};
