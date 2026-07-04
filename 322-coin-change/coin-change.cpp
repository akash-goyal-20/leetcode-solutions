class Solution {
public:
    int f(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (index == coins.size()) {
            if (amount == 0) {
                return 0;
            } else {
                return 1e9;
            }
        }
        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }
        int skip = f(index + 1, coins, amount, dp);
        int take = 1e9;
        if (amount - coins[index] >= 0) {
            take = 1 + f(index, coins, amount - coins[index], dp);
        }

        return dp[index][amount] = min(skip, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(0, coins, amount, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};