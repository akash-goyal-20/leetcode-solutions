class Solution {
public:
    bool check(vector<int>& nums, int k, int allowed) {
        int currentSum = 0;
        int totalSubArray = 1;

        for (int x : nums) {
            if (currentSum + x <= allowed) {
                currentSum += x;
            } else {
                totalSubArray++;
                currentSum = x;
            }
        }

        return totalSubArray <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};