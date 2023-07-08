class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int, vector<int>>> ans;
        int minDistance = INT_MAX;
        int closestIndex = -1;
        
        for (int i = 0; i < points.size(); i++) {
            int distance = abs(x - points[i][0]) + abs(y - points[i][1]);
            
            if (points[i][0] == x || points[i][1] == y) {
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }
        }
        
        return closestIndex;
    }
};
