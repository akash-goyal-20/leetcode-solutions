class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int len = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int u = row[i] + r;
                int v = col[i] + c;

                if (u >= 0 && u < m && v >= 0 && v < n && mat[u][v] == 1) {
                    q.push({len + 1, {u, v}});
                    mat[u][v] = 0;
                    ans[u][v] = ans[r][c] + 1;
                }
            }
        }
        return ans;
    }
};