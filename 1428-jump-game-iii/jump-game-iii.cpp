class Solution {
public:
    bool f(int index, vector<int>& arr, vector<int>& vis) {
        if (index < 0 || index >= arr.size())
            return false;

        if (arr[index] == 0)
            return true;

        if (vis[index])
            return false;

        vis[index] = 1;

        return f(index + arr[index], arr, vis) ||
               f(index - arr[index], arr, vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return f(start, arr, vis);
    }
};