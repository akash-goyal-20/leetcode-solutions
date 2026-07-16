class Solution {
public:
    bool check(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (i != c && grid[r][i] == 1) {
                cnt++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (i != r && grid[i][c] == 1) {
                cnt++;
            }
        }
        if (cnt == 0) {
            return false;
        }
        return true;
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && check(i, j, grid)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};