class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        stack<int> st1;
        stack<int> st2;
        vector<int> nse(n, n);
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && heights[st1.top()] > heights[i]) {
                nse[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && heights[st2.top()] > heights[i]) {
                pse[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxArea;
    }
};