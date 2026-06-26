class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({wt, v});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, k});

        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        int maxi = 0;

        while (!q.empty()) {
            int cost = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto it : adj[node]) {
                int wt = it.first;
                int adjNode = it.second;

                if (cost + wt < dis[adjNode]) {
                    dis[adjNode] = cost + wt;
                    q.push({dis[adjNode], adjNode});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            maxi = max(maxi, dis[i]);
        }

        if (maxi == INT_MAX)
            return -1;

        return maxi;
    }
};