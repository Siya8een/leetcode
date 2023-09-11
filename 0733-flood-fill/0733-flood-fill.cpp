class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, int color, vector<vector<int>>& ans, int initialcolor, vector<int>& drow, vector<int>& dcol) {
        ans[sr][sc] = color;  // Update the current cell with the new color
        int n = image.size();
        int m = image[0].size();
        
        for (int i = 0; i < 4; i++) {
       
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialcolor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, image, color, ans, initialcolor, drow, dcol); 
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        
        dfs(sr, sc, image, color, ans, initialcolor, drow, dcol);
        
        return ans;
    }
};
