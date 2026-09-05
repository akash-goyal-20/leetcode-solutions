class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index, vector<int>& path, int target,
               vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        solve(index + 1, path, target, candidates);

        if (target >= candidates[index]) {
            path.push_back(candidates[index]);
            solve(index, path, target - candidates[index], candidates);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        solve(0, path, target, candidates);
        return ans;
    }
};