class Solution {
public:
    int f(int index, vector<int>& nums, vector<int>& dp, int n) {
        if (index >= n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int skip = f(index + 1, nums, dp, n);
        int take = nums[index] + f(index + 2, nums, dp, n);

        return dp[index] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp, n);
    }
};