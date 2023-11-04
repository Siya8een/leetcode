class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Initialize adjacency list

        for (const vector<int>& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
        }

        vector<int> indegree(numCourses, 0);

        // Calculate indegrees for each course
        for (int i = 0; i < numCourses; i++) {
            for (int course : adj[i]) {
                indegree[course]++;
            }
        }

        queue<int> q;

        // Add courses with indegree 0 to the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int course : adj[node]) {
                indegree[course]--;

                if (indegree[course] == 0) {
                    q.push(course);
                }
            }
        }

        return ans.size() == numCourses;
    }
};
