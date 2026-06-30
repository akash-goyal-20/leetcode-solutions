class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;

        if(n == 1){
            return nums[0];
        }

        while (low <= high) {
            int mid = (low + high) / 2;

            if (mid == 0) {
                if (nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                } else {
                    low = mid + 1;
                }
            } else if (mid == n - 1) {
                if (nums[mid] != nums[mid - 1]) {
                    return nums[mid];
                } else {
                    high = mid - 1;
                }
            } else {
                if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                } else {
                    if (mid % 2 == 0) {
                        if (nums[mid] == nums[mid + 1]) {
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    } else {
                        if (nums[mid] == nums[mid - 1]) {
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};