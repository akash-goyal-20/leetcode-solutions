class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int index = -1;

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                index = i - 1;
                break;
            }
        }
        int swap_index = index;

        if (index != -1) {
            for (int i = n - 1; i >= index + 1; i--) {
                if (nums[i] > nums[index]) {
                    swap_index = i;
                    break;
                }
            }
            swap(nums[index], nums[swap_index]);
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};