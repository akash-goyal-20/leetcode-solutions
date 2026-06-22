class Solution {
public:
    bool dfs(int node, int parent, vector<int>& vis, vector<int>& pathvis,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, node, vis, pathvis, adj)) {
                    return true;
                }
            } else if (pathvis[it] == 1) {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, -1, vis, pathvis, adj)) {
                    return false;
                }
            }
        }

        return true;
    }
};