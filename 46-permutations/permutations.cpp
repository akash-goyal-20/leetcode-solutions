class Solution {
public:
    void f(int n, vector<int>& mark, vector<int>& ds, vector<int>& nums,
           vector<vector<int>>& ans) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (mark[i] == 0) {
                ds.push_back(nums[i]);
                mark[i] = 1;
                f(n, mark, ds, nums, ans);
                ds.pop_back();
                mark[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> mark(n, 0);
        vector<vector<int>> ans;
        vector<int> ds;

        f(n, mark, ds, nums, ans);

        return ans;
    }
};