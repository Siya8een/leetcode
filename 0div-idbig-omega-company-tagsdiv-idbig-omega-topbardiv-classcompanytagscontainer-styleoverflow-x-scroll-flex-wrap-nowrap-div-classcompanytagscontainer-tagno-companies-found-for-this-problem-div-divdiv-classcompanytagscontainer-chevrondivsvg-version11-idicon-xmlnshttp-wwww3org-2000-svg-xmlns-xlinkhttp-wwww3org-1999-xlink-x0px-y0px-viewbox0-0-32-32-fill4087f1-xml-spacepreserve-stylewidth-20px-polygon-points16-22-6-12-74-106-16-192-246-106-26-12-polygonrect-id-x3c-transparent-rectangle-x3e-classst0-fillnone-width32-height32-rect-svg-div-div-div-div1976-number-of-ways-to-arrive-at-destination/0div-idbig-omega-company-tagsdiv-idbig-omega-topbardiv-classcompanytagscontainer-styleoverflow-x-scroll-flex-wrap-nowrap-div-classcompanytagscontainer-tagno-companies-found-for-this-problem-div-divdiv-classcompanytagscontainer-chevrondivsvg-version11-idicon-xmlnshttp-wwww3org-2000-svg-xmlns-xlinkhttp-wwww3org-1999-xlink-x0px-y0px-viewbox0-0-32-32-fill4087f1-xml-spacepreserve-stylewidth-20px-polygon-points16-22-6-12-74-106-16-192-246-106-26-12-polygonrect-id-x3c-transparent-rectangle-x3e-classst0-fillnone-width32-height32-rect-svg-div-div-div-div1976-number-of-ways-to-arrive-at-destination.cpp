#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    int countPaths(int n, std::vector<std::vector<int>>& roads) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);

        for (const auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        std::priority_queue<std::pair<long long int, int>, std::vector<std::pair<long long int, int>>, std::greater<std::pair<long long int, int>>> pq;

        std::vector<long long int> dist(n, LLONG_MAX);
        std::vector<long long int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            long long int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (const auto& it : adj[node]) {
                int adjNode = it.first;
                long long int edW = it.second;

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                } else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return static_cast<int>(ways[n - 1] % mod);
    }
};
