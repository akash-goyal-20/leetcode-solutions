class Solution {
public:
    long long countLessOrEqual(vector<int>& nums, int limit) {
        int left = 0;
        int right = nums.size() - 1;
        long long ans = 0;

        while (left < right) {
            if (nums[left] + nums[right] <= limit) {
                ans += (right - left);
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long pairsTillUpper = countLessOrEqual(nums, upper);
        long long pairsTillLowerMinusOne = countLessOrEqual(nums, lower - 1);

        return pairsTillUpper - pairsTillLowerMinusOne;
    }
};