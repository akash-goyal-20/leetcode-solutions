class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }
        int index = 0;
        for (index = 0; index < temp.size(); index++) {
            nums[index] = temp[index];
        }

        for (int i = index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};