class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> hashmap(256, 0);
            for (int j = i; j < s.size(); j++) {
                hashmap[s[j]]++;
                if (hashmap[s[j]] > 1) {
                    break;
                }
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};