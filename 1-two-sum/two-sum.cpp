class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[nums[0]] = 0;

        for (int i = 1; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (mp.find(rem) != mp.end()) {
                return {i, mp[rem]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};