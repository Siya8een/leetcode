class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDistance = INT_MAX;
        int closestIndex = -1;

        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }
        }

        return closestIndex;
    }
};
