class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        string reqWord;

        while (ss >> word) {
            reqWord = word;
        }

        return reqWord.size();
    }
};