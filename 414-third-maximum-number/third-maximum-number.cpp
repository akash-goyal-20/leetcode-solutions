class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long largest = LONG_MIN;
        long long slargest = LONG_MIN;
        long long tlargest = LONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                tlargest = slargest;
                slargest = largest;
                largest = nums[i];
            } else if (nums[i] < largest && nums[i] > slargest) {
                tlargest = slargest;
                slargest = nums[i];
            } else if (nums[i] < slargest && nums[i] > tlargest) {
                tlargest = nums[i];
            }
        }

        if (tlargest == LONG_MIN) {
            return largest;
        }
        return tlargest;
    }
};