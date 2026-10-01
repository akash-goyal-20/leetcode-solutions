class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        int maxi = -1;
        for (int i = size - 1; i >= 0; i--) {
            int lar = maxi;
            maxi = max(maxi, arr[i]);
            arr[i] = lar;
        }

        return arr;
    }
};