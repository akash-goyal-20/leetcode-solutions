class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> vis;
        vis.insert(beginWord);

        int level = 1;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string s = q.front();
                q.pop();

                if (s == endWord)
                    return level;

                string temp = s;

                for (int i = 0; i < temp.size(); i++) {

                    temp = s;

                    for (char c = 'a'; c <= 'z'; c++) {

                        temp[i] = c;

                        if (st.find(temp) != st.end() &&
                            vis.find(temp) == vis.end()) {

                            vis.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};