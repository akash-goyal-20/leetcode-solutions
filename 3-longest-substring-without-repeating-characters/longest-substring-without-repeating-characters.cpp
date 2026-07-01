class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hashmap(256, -1);

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {

            if (hashmap[s[r]] >= l) {
                l = hashmap[s[r]] + 1;
            }

            hashmap[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};