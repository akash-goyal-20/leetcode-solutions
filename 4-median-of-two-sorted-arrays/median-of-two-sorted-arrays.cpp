class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int l1 = nums1.size();
        int l2 = nums2.size();
        int i = 0;
        int j = 0;

        while (i < l1 && j < l2) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < l1) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < l2) {
            ans.push_back(nums2[j]);
            j++;
        }

        int n = ans.size();
        if (n % 2 == 1) {
            return ans[n / 2];
        } else {
            int k = n / 2;
            return (double)(ans[k] + ans[k - 1]) / 2;
        }
    }
};