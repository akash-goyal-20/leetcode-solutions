class Solution {
public:
    bool f(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (index > nums.size() - 1 && target != 0) {
            return false;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        bool take = false;
        if (nums[index] <= target) {
            take = f(index + 1, target - nums[index], nums, dp);
        }
        bool ntake = f(index + 1, target, nums, dp);

        return dp[index][target] = take || ntake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum = totalSum + nums[i];
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(0, target, nums, dp);
    }
};