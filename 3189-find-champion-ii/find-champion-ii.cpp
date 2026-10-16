
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][1];
            indegree[v]++;
        }

        int count = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans = i;
                count++;
            }
        }

        if (count != 1) {
            return -1;
        }

        return ans;
    }
};
