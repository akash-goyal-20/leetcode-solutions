class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;
    }
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int multiplier = 1;
        while (true) {
            int number = k * multiplier;
            if (binarySearch(nums, number) == false) {
                return number;
            }
            multiplier++;
        }
    }
};