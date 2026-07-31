class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, int m, int n) {
        grid[r][c] = '2';

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int u = r + row[i];
            int v = c + col[i];

            if (u >= 0 && u < m && v >= 0 && v < n && grid[u][v] == '1') {
                dfs(u, v, grid, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};