class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = 1;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int u = row[i] + r;
            int v = col[i] + c;

            if (u >= 0 && u < m && v >= 0 && v < n && vis[u][v] == 0 &&
                grid[u][v] == '1') {
                dfs(u, v, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};