class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;

        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int minlen = min(s1.size(), s2.size());
            bool flag = false;

            for (int j = 0; j < minlen; j++) {

                if (mp[s1[j]] < mp[s2[j]]) {
                    flag = true;
                    break;
                } else if (mp[s1[j]] > mp[s2[j]]) {
                    return false;
                }
            }
            if (!flag && s1.size() > s2.size()) {
                return false;
            }
        }

        return true;
    }
};