class Solution {
public:
    bool f(vector<int>& nums, int index, vector<int>& dp) {
        if (index == nums.size() - 1) {
            return true;
        }
        if (index >= nums.size() || nums[index] == 0) {
            return false;
        }
        if (dp[index] != -1)
            return dp[index];

        for (int i = 1; i <= nums[index]; i++) {
            if (f(nums, index + i, dp))
                return dp[index] = true;
        }

        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(nums, 0, dp);
    }
};