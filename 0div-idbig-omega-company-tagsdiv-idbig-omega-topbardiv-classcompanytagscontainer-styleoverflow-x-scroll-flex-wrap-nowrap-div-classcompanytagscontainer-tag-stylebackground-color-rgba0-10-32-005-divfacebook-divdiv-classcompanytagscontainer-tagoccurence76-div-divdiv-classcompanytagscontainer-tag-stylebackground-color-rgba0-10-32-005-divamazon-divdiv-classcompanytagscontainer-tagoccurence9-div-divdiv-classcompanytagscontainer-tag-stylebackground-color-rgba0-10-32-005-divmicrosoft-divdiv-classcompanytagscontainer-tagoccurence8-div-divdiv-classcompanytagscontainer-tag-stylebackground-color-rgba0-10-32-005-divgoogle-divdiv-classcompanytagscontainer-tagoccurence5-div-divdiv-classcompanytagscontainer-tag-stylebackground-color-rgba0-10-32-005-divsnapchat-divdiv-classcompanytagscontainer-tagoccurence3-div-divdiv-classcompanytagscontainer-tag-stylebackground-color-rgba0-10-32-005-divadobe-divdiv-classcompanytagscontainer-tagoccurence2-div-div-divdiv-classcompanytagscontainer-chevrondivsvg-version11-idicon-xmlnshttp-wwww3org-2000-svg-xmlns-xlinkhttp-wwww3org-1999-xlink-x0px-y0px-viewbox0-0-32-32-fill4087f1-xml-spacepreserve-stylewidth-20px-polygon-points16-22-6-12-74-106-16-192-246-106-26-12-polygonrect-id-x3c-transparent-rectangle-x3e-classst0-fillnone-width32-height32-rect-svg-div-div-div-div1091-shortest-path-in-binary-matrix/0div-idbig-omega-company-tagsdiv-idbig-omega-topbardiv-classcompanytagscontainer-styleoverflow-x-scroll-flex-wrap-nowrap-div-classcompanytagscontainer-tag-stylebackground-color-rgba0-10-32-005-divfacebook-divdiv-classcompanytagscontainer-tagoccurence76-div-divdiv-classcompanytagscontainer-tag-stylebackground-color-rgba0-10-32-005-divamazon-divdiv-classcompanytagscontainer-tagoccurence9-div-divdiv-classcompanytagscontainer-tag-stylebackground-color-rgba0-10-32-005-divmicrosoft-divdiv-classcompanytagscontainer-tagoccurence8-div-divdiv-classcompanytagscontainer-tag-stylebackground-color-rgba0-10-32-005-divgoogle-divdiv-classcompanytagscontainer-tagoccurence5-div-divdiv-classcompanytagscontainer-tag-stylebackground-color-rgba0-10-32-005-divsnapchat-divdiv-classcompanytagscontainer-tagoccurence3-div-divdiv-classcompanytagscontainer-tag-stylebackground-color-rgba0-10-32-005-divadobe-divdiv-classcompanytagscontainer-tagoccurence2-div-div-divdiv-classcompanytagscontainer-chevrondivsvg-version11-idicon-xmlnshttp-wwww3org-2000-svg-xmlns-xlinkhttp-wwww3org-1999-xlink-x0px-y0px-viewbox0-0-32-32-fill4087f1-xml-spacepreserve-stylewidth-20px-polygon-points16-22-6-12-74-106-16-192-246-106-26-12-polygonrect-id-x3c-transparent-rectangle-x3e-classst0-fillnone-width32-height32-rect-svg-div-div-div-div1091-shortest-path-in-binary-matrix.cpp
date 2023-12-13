class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // To store if visited or not
        vector<vector<bool>> visited(n, vector<bool>(n));

        // Using BFS
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(0, 0), 1));

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int value = q.front().second;
            q.pop();

            // If current is out of bounds or is 1 or visited, skip it
            if(min(i, j)<0 || max(i, j)>=n || grid[i][j] || visited[i][j]) continue;

            // If the target node is reached, return current value. As, we use BFS, we will get only shortest path
            if(i == n-1 && j == n-1) return value;

            // Mark visited and add cells in all directions
            visited[i][j] = true;
            q.push(make_pair(make_pair(i-1, j-1), value+1));
            q.push(make_pair(make_pair(i-1, j), value+1));
            q.push(make_pair(make_pair(i-1, j+1), value+1));

            q.push(make_pair(make_pair(i, j-1), value+1));
            q.push(make_pair(make_pair(i, j+1), value+1));

            q.push(make_pair(make_pair(i+1, j-1), value+1));
            q.push(make_pair(make_pair(i+1, j), value+1));
            q.push(make_pair(make_pair(i+1, j+1), value+1));
        }
        return -1;
    }
private:

};