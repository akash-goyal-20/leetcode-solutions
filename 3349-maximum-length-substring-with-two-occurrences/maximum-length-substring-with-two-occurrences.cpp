class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int maxlen = 0;
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;

            while (freq[s[i]] > 2) {
                freq[s[j]]--;
                j++;
            }

            maxlen = max(maxlen, i - j + 1);
        }

        return maxlen;
    }
};