class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        unordered_map<char, int> mp;

        for (int i = 0; i < ransomNote.size(); i++) {
            mp[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++) {
            if (mp[magazine[i]] > 0) {
                mp[magazine[i]]--;
            }
        }
        for (auto it : mp) {
            if (it.second > 0) {
                return false;
            }
        }
        return true;
    }
};