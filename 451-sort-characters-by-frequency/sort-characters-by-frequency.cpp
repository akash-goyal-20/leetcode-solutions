class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(),
             [](const pair<char, int> a, const pair<char, int> b) {
                 return a.second > b.second;
             });

        for (auto it : v) {
            for (int i = 0; i < it.second; i++) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};