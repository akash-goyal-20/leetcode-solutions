class Solution {
public:
    string smallestPalindrome(string s) {
        string ans;

        int n = s.size();
        if (n == 1) {
            return s;
        }
        int half = n / 2;
        string temp = s.substr(0, half);
        sort(temp.begin(), temp.end());
        ans = ans + temp;

        if (n % 2 != 0) {
            ans = ans + s[half];
        }
        
        reverse(temp.begin(), temp.end());
        ans = ans + temp;

        return ans;
    }
};