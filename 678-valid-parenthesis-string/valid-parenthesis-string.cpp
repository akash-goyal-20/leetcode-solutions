class Solution {
public:
    bool f(int index, string& s, int cnt, vector<vector<int>>& dp) {
        if (cnt < 0)
            return false;

        if (index == s.size())
            return cnt == 0;

        if (dp[index][cnt] != -1)
            return dp[index][cnt];

        bool ans;

        if (s[index] == '(') {
            ans = f(index + 1, s, cnt + 1, dp);
        } else if (s[index] == ')') {
            ans = f(index + 1, s, cnt - 1, dp);
        } else {
            ans = f(index + 1, s, cnt + 1, dp) ||
                  f(index + 1, s, cnt - 1, dp) || f(index + 1, s, cnt, dp);
        }

        return dp[index][cnt] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, s, 0, dp);
    }
};