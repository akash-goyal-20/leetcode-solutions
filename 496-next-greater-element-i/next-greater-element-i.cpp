class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        int n = nums2.size();
        stack<int> st;
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) != mp.end()) {
                ans[i] = mp[nums1[i]];
            }
        }

        return ans;
    }
};