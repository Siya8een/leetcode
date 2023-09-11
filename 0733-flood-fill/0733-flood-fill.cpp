class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc]; // Store the original color
        
        if (oldColor == newColor) {
            return image; // No need to perform flood fill if the new color is the same as the old color
        }
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        q.push({sr, sc});
        vis[sr][sc] = 1; // Mark the starting pixel as visited
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            image[r][c] = newColor; // Change the color of the current pixel
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && image[nrow][ncol] == oldColor) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; // Mark the neighboring pixel as visited
                }
            }
        }
        
        return image;
    }
};
