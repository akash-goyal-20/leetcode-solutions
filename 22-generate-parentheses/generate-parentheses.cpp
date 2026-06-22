class Solution {
public:
    vector<string> ans;

    void f(int curr, int n, string s, int closed, int open) {
        if (curr == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            f(curr + 1, n, s + '(', closed, open + 1);
        }

        if (open > closed) {
            f(curr + 1, n, s + ')', closed + 1, open);
        }
    }

    vector<string> generateParenthesis(int n) {
        f(0, n, "", 0, 0);
        return ans;
    }
};