class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) {
            return {0};
        }
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};