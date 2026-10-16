class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i1 = 0;
        int i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1][0] == nums2[i2][0]) {
                int id = nums1[i1][0];
                int value = nums1[i1][1] + nums2[i2][1];
                ans.push_back({id, value});
                i1++;
                i2++;
            } else if (nums1[i1][0] < nums2[i2][0]) {
                int id = nums1[i1][0];
                int value = nums1[i1][1];
                ans.push_back({id, value});
                i1++;
            } else {
                int id = nums2[i2][0];
                int value = nums2[i2][1];
                ans.push_back({id, value});
                i2++;
            }
        }

        while (i1 < nums1.size()) {
            int id = nums1[i1][0];
            int value = nums1[i1][1];
            ans.push_back({id, value});
            i1++;
        }

        while (i2 < nums2.size()) {
            int id = nums2[i2][0];
            int value = nums2[i2][1];
            ans.push_back({id, value});
            i2++;
        }

        return ans;
    }
};