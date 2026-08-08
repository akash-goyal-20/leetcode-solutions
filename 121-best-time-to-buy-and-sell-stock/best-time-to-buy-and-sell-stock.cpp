class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minStock = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] - minStock > 0) {
                maxProfit = max(maxProfit, prices[i] - minStock);
            }
            if (minStock > prices[i]) {
                minStock = prices[i];
            }
        }

        return maxProfit;
    }
};