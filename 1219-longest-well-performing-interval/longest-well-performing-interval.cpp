class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int tiring = 0;
            int ntiring = 0;
            for (int j = i; j < n; j++) {
                if (hours[j] > 8) {
                    tiring++;
                } else {
                    ntiring++;
                }
                if (tiring > ntiring) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};