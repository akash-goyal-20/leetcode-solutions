class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 1;
        }
        int rank = 1;
        for (auto it : mp) {
            mp[it.first] = rank;
            rank++;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};