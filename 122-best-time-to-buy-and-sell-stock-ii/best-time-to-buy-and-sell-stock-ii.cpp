class Solution {
public:
    int solve(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        // No more days
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }
        if (canBuy) {

            // Buy
            int buy = -prices[i] + solve(i + 1, 0, prices, dp);

            // Don't buy
            int skip = solve(i + 1, 1, prices, dp);

            return dp[i][canBuy] = max(buy, skip);

        } else {

            // Sell
            int sell = prices[i] + solve(i + 1, 1, prices, dp);

            // Don't sell
            int skip = solve(i + 1, 0, prices, dp);

            return dp[i][canBuy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};