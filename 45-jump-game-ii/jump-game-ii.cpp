class Solution {
public:
    long long f(int index, vector<int>& nums, vector<int>& dp){
        if(index >= nums.size() - 1)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        long long mini = INT_MAX;

        for(int jump = 1; jump <= nums[index]; jump++){
            if(index + jump < nums.size()){
                mini = min(mini, 1 + f(index + jump, nums, dp));
            }
        }

        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(0, nums, dp);
    }
};