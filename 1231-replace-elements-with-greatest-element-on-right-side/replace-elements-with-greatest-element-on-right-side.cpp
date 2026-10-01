class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();

        for (int i = 0; i < size - 1; i++) {
            int maxi = INT_MIN;

            for (int j = i + 1; j < size; j++) {
                maxi = max(arr[j], maxi);
            }
            arr[i] = maxi;
        }
        arr[size - 1] = -1;

        return arr;
    }
};