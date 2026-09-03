class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            vector<int> prev = ans.back();
            if (intervals[i][0] <= prev[1]) {
                ans.pop_back();
                vector<int> newInterval = {prev[0], max(prev[1],intervals[i][1])};
                ans.push_back(newInterval);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};