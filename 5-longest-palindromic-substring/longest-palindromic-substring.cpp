class Solution {
public:
    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        } else {
            return dp[i][j] = false;
        }
    }
    string longestPalindrome(string s) {
        int maxi = 0;
        string ans = "";
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s, dp)) {
                    if (j - i + 1 > maxi) {
                        ans = s.substr(i, j - i + 1);
                        maxi = j - i + 1;
                    }
                }
            }
        }

        return ans;
    }
};