class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int val = abs(x1 - x2) + abs(y1 - y2);

                if (i != j) {
                    adj[i].push_back({val, j});
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});
        vector<int> vis(n, 0);

        int sum = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum = sum + wt;

            for (auto it : adj[node]) {
                int adjNode = it.second;
                int adjwt = it.first;

                if (vis[adjNode] == 0) {
                    pq.push({adjwt, adjNode});
                }
            }
        }

        return sum;
    }
};