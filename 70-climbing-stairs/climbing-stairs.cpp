class Solution {
public:
    int f(int index, int n, vector<int>& dp) {
        if (index == n) {
            return 1;
        }
        if (index > n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int oneStep = f(index + 1, n, dp);
        int twoStep = f(index + 2, n, dp);

        return dp[index] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return f(0, n, dp);
    }
};