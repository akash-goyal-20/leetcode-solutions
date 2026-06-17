class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st1;
        stack<int> st2;

        for (int i = 0; i < heights.size(); i++) {
            while (!st1.empty() && heights[i] < heights[st1.top()]) {
                nse[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        for (int i = 0; i < heights.size(); i++) {
            while (!st2.empty() && heights[i] < heights[st2.top()]) {
                st2.pop();
            }
            if (!st2.empty()) {
                pse[i] = st2.top();
            }
            st2.push(i);
        }
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxi;
    }
};