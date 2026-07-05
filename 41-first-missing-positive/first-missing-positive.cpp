class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<int> present(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 1 && nums[i] <= n)
                present[nums[i]] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!present[i])
                return i;
        }

        return n + 1;
    }
};