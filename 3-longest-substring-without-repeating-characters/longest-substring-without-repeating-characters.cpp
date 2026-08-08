class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> mp;

        int left = 0;
        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            if (mp.find(s[i]) != mp.end()) {
                left = max(left, mp[s[i]] + 1);
            }
            maxi = max(maxi, i - left + 1);

            mp[s[i]] = i;
        }

        return maxi;
    }
};