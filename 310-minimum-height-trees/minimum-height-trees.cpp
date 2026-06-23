class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) return {0};

        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int sz = q.size();

            ans.clear(); 

            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();

                ans.push_back(node);

                for (auto it : adj[node]) {
                    degree[it]--;

                    if (degree[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }

        return ans;
    }
};