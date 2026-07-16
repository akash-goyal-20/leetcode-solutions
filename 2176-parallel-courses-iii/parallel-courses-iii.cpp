class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> Earliest(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);

        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0];
            int v = relations[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (Earliest[it] < Earliest[node] + time[node - 1]) {
                    Earliest[it] = Earliest[node] + time[node - 1];
                }

                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = max(ans, Earliest[i] + time[i - 1]);
        }

        return ans;
    }
};