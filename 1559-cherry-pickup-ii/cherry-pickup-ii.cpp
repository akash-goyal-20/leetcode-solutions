class Solution {
public:
    int solve(int row, int col1, int col2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Invalid columns
        if (col1 < 0 || col1 >= n ||
            col2 < 0 || col2 >= n) {
            return -1e9;
        }

        // Already calculated
        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }

        // Current cherries
        int curr;

        if (col1 == col2) {
            curr = grid[row][col1];
        } else {
            curr = grid[row][col1] + grid[row][col2];
        }

        // Last row
        if (row == m - 1) {
            return dp[row][col1][col2] = curr;
        }

        int ans = 0;

        // 9 combinations
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                ans = max(
                    ans,
                    solve(row + 1,
                          col1 + d1,
                          col2 + d2,
                          grid,
                          dp)
                );
            }
        }

        return dp[row][col1][col2] = curr + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(n, -1))
        );

        return solve(0, 0, n - 1, grid, dp);
    }
};