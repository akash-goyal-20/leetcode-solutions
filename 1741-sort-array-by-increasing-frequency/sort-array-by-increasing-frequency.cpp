class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });

        for (auto it : v) {
            for (int i = 0; i < it.second; i++) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};