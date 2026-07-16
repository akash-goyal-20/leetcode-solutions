class Solution {
public:
    int cnt = 0;

    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            int next = it.first;
            int cost = it.second;

            if (!vis[next]) {
                cnt += cost;
                dfs(next, adj, vis);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            // Original edge u -> v
            adj[u].push_back({v, 1});

            // Reverse direction
            adj[v].push_back({u, 0});
        }

        vector<int> vis(n, 0);

        dfs(0, adj, vis);

        return cnt;
    }
};