class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle,
          vector<vector<int>>& dp) {
        int n = triangle.size();
        if (i == n - 1) {
            return triangle[i][j];  
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        int c1 = f(i + 1, j, triangle, dp);
        int c2 = f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(c1, c2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        return f(0, 0, triangle, dp);
    }
};