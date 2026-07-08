class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(n - k);
        for (int i = 0; i < n - k; i++) {
            temp[i] = nums[i];
        }
        int j = 0;
        for (int i = n - k; i < n; i++) {
            nums[j] = nums[i];
            j++;
        }
        int l = 0;
        for (int i = j; i < n; i++) {
            nums[i] = temp[l];
            l++;
        }
    }
};