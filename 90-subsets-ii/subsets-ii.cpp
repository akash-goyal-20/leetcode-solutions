class Solution {
public:
    void print(int ind, set<vector<int>>& ans, vector<int>& nums,
               vector<int>& ds) {
        if (ind == nums.size()) {
            ans.insert(ds);
            return;
        }

        ds.push_back(nums[ind]);
        print(ind + 1, ans, nums, ds);

        ds.pop_back();

        print(ind + 1, ans, nums, ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> a;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        print(0, ans, nums, ds);
        for(auto it : ans){
            a.push_back(it);
        }
        return a;
    }
};