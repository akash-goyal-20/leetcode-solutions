class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        string ans = "";

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {

            freq[s[i] - 'a']--;

            if (vis[s[i] - 'a'])
                continue;

            while (!st.empty() && s[i] < st.top() && freq[st.top() - 'a'] > 0) {

                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i] - 'a'] = true;
        }

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};