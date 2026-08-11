class Solution {
public:
    unordered_set<string> st;
    bool solve(int index, string s, vector<int>& dp) {
        if (index == s.size()) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        for (int i = 1; i <= s.size(); i++) {
            string s1 = s.substr(index, i);
            if (st.find(s1) != st.end()) {
                if (solve(index + i, s, dp)) {
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for (auto& it : wordDict) {
            st.insert(it);
        }
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};