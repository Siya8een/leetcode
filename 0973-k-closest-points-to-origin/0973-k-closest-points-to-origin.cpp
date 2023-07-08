class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> a;
        vector<pair<int, vector<int>>> v;
        
        for (int i = 0; i < points.size(); i++) {
            int s = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({ s, {points[i][0], points[i][1]} });
        }
        
        sort(v.begin(), v.end());
        
        for (int i = 0; i < k; i++) {
            a.push_back(v[i].second);
        }
        
        return a;
    }
};
