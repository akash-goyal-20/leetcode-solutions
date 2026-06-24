class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        int maxi = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(i, j, s)) {
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