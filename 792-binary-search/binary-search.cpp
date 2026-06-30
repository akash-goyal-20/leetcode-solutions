class Solution {
public:
    int f(int low, int high, int target, vector<int>& nums) {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return f(low, mid - 1, target, nums);
        } else {
            return f(mid + 1, high, target, nums);
        }
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return f(low, high, target, nums);
    }
};