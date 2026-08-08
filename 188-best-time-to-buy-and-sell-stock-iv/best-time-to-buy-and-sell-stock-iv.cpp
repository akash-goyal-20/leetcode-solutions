class Solution {
public:
    int f(int index, vector<int>& prices, int canBuy, int transaction,
          vector<vector<vector<int>>>& dp) {
        if (index == prices.size()) {
            return 0;
        }
        if (transaction == 0) {
            return 0;
        }

        if (dp[index][canBuy][transaction] != -1) {
            return dp[index][canBuy][transaction];
        }

        if (canBuy) {
            int buy = -prices[index] + f(index + 1, prices, 0, transaction, dp);
            int skip = f(index + 1, prices, 1, transaction, dp);

            return dp[index][canBuy][transaction] = max(buy, skip);
        } else {
            int sell =
                prices[index] + f(index + 1, prices, 1, transaction - 1, dp);
            int skip = f(index + 1, prices, 0, transaction, dp);

            return dp[index][canBuy][transaction] = max(sell, skip);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, prices, 1, k, dp);
    }
};