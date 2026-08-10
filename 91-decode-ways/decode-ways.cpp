class Solution {
public:
    int f(int index, string& s, vector<int>& dp) {

        if (index == s.size())
            return 1;

        if (s[index] == '0')
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // Take one digit
        int choice1 = f(index + 1, s, dp);

        // Take two digits
        int choice2 = 0;

        if (index + 1 < s.size() && stoi(s.substr(index, 2)) <= 26) {

            choice2 = f(index + 2, s, dp);
        }

        return dp[index] = choice1 + choice2;
    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, s, dp);
    }
};