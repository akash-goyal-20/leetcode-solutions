class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp(26, 0);

        for (int i = 0; i < text.size(); i++) {
            int w = text[i] - 'a';
            mp[w]++;
        }

        string target = "balloon";
        int miniOcc = INT_MAX;

        for (int i = 0; i < target.size(); i++) {
            int w = target[i] - 'a';
            if (target[i] == 'l' || target[i] == 'o') {
                miniOcc = min(miniOcc, mp[w] / 2);
            } else {

                miniOcc = min(miniOcc, mp[w]);
            }
        }

        return miniOcc;
    }
};