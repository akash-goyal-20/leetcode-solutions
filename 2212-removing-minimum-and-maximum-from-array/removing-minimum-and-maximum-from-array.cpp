class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minimum = nums[0];
        int maximum = nums[0];

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maximum) {
                maximum = nums[i];
                maxIndex = i;
            }
            if (nums[i] < minimum) {
                minimum = nums[i];
                minIndex = i;
            }
        }
        int choice1 = max(maxIndex, minIndex) + 1;

        int choice2 = nums.size() - min(maxIndex, minIndex);

        int choice3 = min(maxIndex, minIndex) + 1 +
                      (nums.size() - max(maxIndex, minIndex));

        return min({choice1, choice2, choice3});
    }
};