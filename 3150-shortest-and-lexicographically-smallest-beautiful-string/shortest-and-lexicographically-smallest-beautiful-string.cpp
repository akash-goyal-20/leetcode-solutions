class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int j = 0;
        int cnt = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;

            while (cnt > k) {
                if (s[j] == '1')
                    cnt--;
                j++;
            }

            if (cnt == k) {
                // Remove unnecessary leading zeroes
                while (s[j] == '0')
                    j++;

                string temp = s.substr(j, i - j + 1);

                if (ans == "" ||
                    temp.size() < ans.size() ||
                    (temp.size() == ans.size() && temp < ans)) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};