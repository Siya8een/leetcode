class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;
        
        // Find the maximum distance from left to right
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, n - 1 - i);
                break;
            }
        }
        
        // Find the maximum distance from right to left
        for (int j = n - 1; j > 0; j--) {
            if (colors[j] != colors[0]) {
                maxDist = max(maxDist, j);
                break;
            }
        }
        
        return maxDist;
    }
};
