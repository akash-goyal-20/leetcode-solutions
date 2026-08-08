class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        // map<char, int> mp1;
        // map<char, int> mp2;

        // for (int i = 0; i < s.size(); i++) {
        //     mp1[s[i]]++;
        //     mp2[t[i]]++;
        // }
        // for (int i = 0; i < t.size(); i++) {
        //     if (mp2[t[i]] != mp1[t[i]]) {
        //         return false;
        //     }
        // }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s != t){
            return false;
        }

        return true;
    }
};