class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string temp;
        string ans = "";

        while (ss >> temp) {   // >> ignores extra spaces
            if (ans.empty())
                ans = temp;
            else
                ans = temp + " " + ans;
        }

        return ans;
    }
};