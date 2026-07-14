class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 0;
        int minDiff = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int diff = abs(target - (nums[i] + nums[j] + nums[k]));
                    if (diff < minDiff) {
                        minDiff = diff;
                        closest = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return closest;
    }
};