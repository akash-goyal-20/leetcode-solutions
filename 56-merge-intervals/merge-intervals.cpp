class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            vector<int> r = result.back();
            if (r[1] >= intervals[i][0]) {
                result.pop_back();
                r[1] = max(intervals[i][1],r[1]);
                result.push_back(r);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};