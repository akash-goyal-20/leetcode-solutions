class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2, vector<vector<int>>& vis, bool& flag) {
        if (grid1[r][c] == 0 && grid2[r][c] == 1) {
            flag = true;
        }
        int m = grid1.size();
        int n = grid2[0].size();
        vis[r][c] = 1;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int u = r + row[i];
            int v = c + col[i];

            if (u >= 0 && u < m && v >= 0 && v < n && vis[u][v] == 0) {
                if (grid2[u][v] == 1) {
                    dfs(u, v, grid1, grid2, vis, flag);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int m = grid1.size();
        int n = grid2[0].size();
        int cnt = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && vis[i][j] == 0) {
                    bool flag = false;
                    dfs(i, j, grid1, grid2, vis, flag);
                    if (!flag) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};