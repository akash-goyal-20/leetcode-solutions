class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<int> present(n + 1, 0);

        for (int x : nums) {
            if (x >= 1 && x <= n)
                present[x] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!present[i])
                return i;
        }

        return n + 1;
    }
};