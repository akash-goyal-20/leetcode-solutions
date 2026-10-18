class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }
        int even = INT_MAX;
        int odd = INT_MIN;
        for (auto it : mp) {
            if (it.second % 2 == 0) {
                even = min(even, it.second);
            } else {
                odd = max(odd, it.second);
            }
        }
        return odd - even;
    }
};