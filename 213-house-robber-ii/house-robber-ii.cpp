class Solution {
public:
    int f(int index, int n, vector<int>& nums, vector<int>& dp) {
        if (index >= n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int take = nums[index] + f(index + 2, n, nums, dp);
        int skip = f(index + 1, n, nums, dp);

        return dp[index] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n - 1, -1);
        int first = f(0, n - 1, nums, dp2);
        int last = f(1, n, nums, dp1);

        return max(first, last);
    }
};