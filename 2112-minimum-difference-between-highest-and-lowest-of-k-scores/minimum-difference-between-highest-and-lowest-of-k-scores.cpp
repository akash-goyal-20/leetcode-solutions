class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int left = 0;
        for(int right = 0; right < n; right++){
            if(right - left + 1 == k){
                mini = min((nums[right] - nums[left]),mini);
                left++;
            }
        }
        return mini;
    }
};