class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        // if (n == 2) {
        //     return "11";
        // }
        string s = countAndSay(n - 1);
        string ans = "";
        int cnt = 1;
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[j]) {
                cnt++;
            } else {
                ans = ans + to_string(cnt) + s[j];
                cnt = 1;
                j = i;
            }
        }
        ans = ans + to_string(cnt) + s[j];

        return ans;
    }
};