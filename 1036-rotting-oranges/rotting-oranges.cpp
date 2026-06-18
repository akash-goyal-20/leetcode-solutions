class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        int time = -1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int u = r + row[i];
                    int v = c + col[i];

                    if (u >= 0 && u < m && v >= 0 && v < n && grid[u][v] == 1) {
                        grid[u][v] = 2;
                        q.push({u, v});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if (fresh == 0) {
            return time;
        }
        return -1;
    }
};