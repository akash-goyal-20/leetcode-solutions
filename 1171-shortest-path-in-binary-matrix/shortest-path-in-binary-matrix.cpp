class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1;

        int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int col[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int u = r + row[i];
                int v = c + col[i];

                if (u >= 0 && u < m && v >= 0 && v < n && grid[u][v] == 0) {
                    q.push({dis + 1, {u, v}});
                    grid[u][v] = 1;
                }
            }
            if (r == m - 1 && c == n - 1) {
                return dis;
            }
        }

        return -1;
    }
};