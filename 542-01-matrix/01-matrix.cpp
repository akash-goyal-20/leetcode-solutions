class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int u = r + row[i];
                int v = c + col[i];

                if (u >= 0 && u < m && v >= 0 && v < n && vis[u][v] == 0) {
                    dis[u][v] = dis[r][c] + 1;
                    vis[u][v] = 1;
                    q.push({u, v});
                }
            }
        }

        return dis;
    }
};