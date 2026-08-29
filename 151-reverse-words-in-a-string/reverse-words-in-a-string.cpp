class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }
        reverse(arr.begin(), arr.end());
        string ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            ans = ans + " " + arr[i];
        }
        return ans;
    }
};