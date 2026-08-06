class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;

        for(auto c : s){
            mp[c]++;
        }
        
        for(auto c : t){
            if(mp[c] == 0){
                return c;
            }
            mp[c]--;
        }
        return 'a';
    }
};