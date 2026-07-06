class Solution {
public:
    vector<vector<int>> ans;
    void f(int index, vector<int>& nums, vector<int> subset) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        f(index + 1, nums, subset);
        subset.pop_back();
        f(index + 1, nums, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        f(0, nums, subset);
        return ans;
    }
};