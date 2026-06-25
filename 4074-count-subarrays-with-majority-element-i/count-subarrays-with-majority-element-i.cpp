class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < n; j++) {
                freq[nums[j]]++;

                if (freq[target] > (j - i + 1) / 2)
                    cnt++;
            }
        }

        return cnt;
    }
};