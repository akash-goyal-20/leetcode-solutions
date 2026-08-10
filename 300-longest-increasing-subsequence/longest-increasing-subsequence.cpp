class Solution {
public:
    int LIS(int prev, int index, vector<int>& nums,
            vector<vector<int>>& dp) {

        if (index >= nums.size())
            return 0;

        if (dp[prev + 1][index] != -1)
            return dp[prev + 1][index];

        int pick = 0;

        if (prev == -1 || nums[index] > nums[prev]) {
            pick = 1 + LIS(index, index + 1, nums, dp);
        }

        int skip = LIS(prev, index + 1, nums, dp);

        return dp[prev + 1][index] = max(pick, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n, -1)
        );

        return LIS(-1, 0, nums, dp);
    }
};