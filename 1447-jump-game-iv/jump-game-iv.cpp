class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        while (!q.empty()) {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();
            if (node == n - 1) {
                return wt;
            }
            if (node + 1 < n && wt + 1 < dis[node + 1]) {
                dis[node + 1] = wt + 1;
                q.push({node + 1, wt + 1});
            }
            if (node - 1 >= 0 && wt + 1 < dis[node - 1]) {
                dis[node - 1] = wt + 1;
                q.push({node - 1, wt + 1});
            }
            for (int next : mp[arr[node]]) {
                if (dis[next] > wt + 1) {
                    dis[next] = wt + 1;
                    q.push({next, wt + 1});
                }
            }

            mp.erase(arr[node]);
        }

        return -1;
    }
};