class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        stack<char> st;

        for (auto it : s) {
            if (it == '(') {
                st.push(it);
            } else {
                if (st.empty())
                    return false;
                if (st.top() == '(' && it == ')') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
    void f(int n, string& s) {
        if (n == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }

            return;
        }
        string c1 = s + '(';
        string c2 = s + ')';
        f(n - 1, c1);
        f(n - 1, c2);
    }
    vector<string> generateParenthesis(int n) {
        string s;
        f(2 * n, s);
        return ans;
    }
};