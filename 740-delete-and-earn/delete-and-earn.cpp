// House robber in disguise
class Solution {
public:
    int f(int index, vector<int>& freq,vector<int>& dp){
        if(index >= freq.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take = freq[index] + f(index+2,freq,dp);
        int skip = f(index+1,freq,dp);

        return dp[index]=max(take,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }
        vector<int> freq(maxi+1,0);
        vector<int> dp(maxi+1,-1);

        for(int i = 0; i < n; i++){
            freq[nums[i]] = freq[nums[i]] + nums[i];
        }
        return f(0,freq,dp);
    }
};