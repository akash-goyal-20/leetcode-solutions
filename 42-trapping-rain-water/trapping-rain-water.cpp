class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Maximum height from left
        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Maximum height from right
        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int totalRain = 0;

        for (int i = 0; i < n; i++) {

            int amount = min(leftMax[i], rightMax[i]) - height[i];

            totalRain += amount;
        }

        return totalRain;
    }
};