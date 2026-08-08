class Solution {
public:
    int rightMax(int element, vector<int>& height) {
        int n = height.size();
        if (element == n - 1) {
            return -1;
        }
        int maxi = height[element];
        for (int i = element + 1; i < n; i++) {
            maxi = max(maxi, height[i]);
        }
        if (maxi == height[element]) {
            return -1;
        }
        return maxi;
    }
    int lefttMax(int element, vector<int>& height) {
        int n = height.size();
        if (element == 0) {
            return -1;
        }
        int maxi = height[element];
        for (int i = element - 1; i >= 0; i--) {
            maxi = max(maxi, height[i]);
        }
        if (maxi == height[element]) {
            return -1;
        }
        return maxi;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int totalRain = 0;
        for (int i = 0; i < n; i++) {
            if (rightMax(i, height) == -1 || lefttMax(i, height) == -1) {
                continue;
            }
            int amount =
                min(rightMax(i, height), lefttMax(i, height)) - height[i];
            totalRain = totalRain + amount;
        }

        return totalRain;
    }
};