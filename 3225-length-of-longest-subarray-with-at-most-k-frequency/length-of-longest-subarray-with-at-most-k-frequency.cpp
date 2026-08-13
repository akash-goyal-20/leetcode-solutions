class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int j = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;

            while(freq[nums[i]] > k){
                freq[nums[j]]--;
                j++;
            }
            maxi = max(maxi, i - j + 1);
        }

        return maxi;
    }
};