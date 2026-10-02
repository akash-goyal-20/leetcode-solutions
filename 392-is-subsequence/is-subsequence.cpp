class Solution {
public:
    bool solve(int i, int j, string s, string t) {
        if (i == s.size()) {
            return true;
        }
        if (j == t.size()) {
            return false;
        }
        for (int k = j; k < t.size(); k++) {
            if (s[i] == t[k]) {
                return solve(i + 1, k + 1, s, t);
            }
        }
        return false;
    }
    bool isSubsequence(string s, string t) { return solve(0, 0, s, t); }
};