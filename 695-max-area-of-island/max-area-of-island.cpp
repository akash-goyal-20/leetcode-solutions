class Solution {
public:
    int maxi = 0;
    int count = 0;
    void dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        grid[r][c] = -1;
        count++;
        maxi = max(maxi, count);

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int u = r + row[i];
            int v = c + col[i];

            if (u >= 0 && u < m && v >= 0 && v < n && grid[u][v] == 1) {
                dfs(u, v, m, n, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count = 0;
                    dfs(i, j, m, n, grid);
                }
            }
        }
        return maxi;
    }
};