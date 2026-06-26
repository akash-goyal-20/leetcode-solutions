class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dis[node])
                continue;

            for (auto it : adj[node]) {
                int wt = it.first;
                int adjNode = it.second;

                if (cost + wt < dis[adjNode]) {
                    dis[adjNode] = cost + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dis[adjNode], adjNode});
                }
                else if (cost + wt == dis[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};