class Solution {
public:
    bool f(int index, vector<int>& nums, vector<int>& dp) {
        if (index == nums.size() - 1) {
            return true;
        }
        if (index > nums.size() - 1 || nums[index] == 0) {
            return false;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        bool reach = false;

        for (int i = 1; i <= nums[index]; i++) {
            if (f(index + i, nums, dp))
                return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};