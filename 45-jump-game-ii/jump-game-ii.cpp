class Solution {
public:
    int f(int index, vector<int>& nums, vector<int>& dp) {
        if (index == nums.size() - 1) {
            return 0;
        }
        if (index > nums.size() - 1 || nums[index] == 0) {
            return 1e9;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int minJump = 1e9;
        for (int i = 1; i <= nums[index]; i++) {
            minJump = min(minJump, f(index + i, nums, dp));
        }
        return dp[index] = minJump + 1;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(0, nums, dp);
    }
};