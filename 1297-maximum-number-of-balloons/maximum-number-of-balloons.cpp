class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp(26, 0);

        for(char c : text) {
            mp[c - 'a']++;
        }

        return min({
            mp['b' - 'a'],
            mp['a' - 'a'],
            mp['l' - 'a'] / 2,
            mp['o' - 'a'] / 2,
            mp['n' - 'a']
        });
    }
};