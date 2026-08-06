class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left = 0;
        int cnt = 0;
        long long sum = 0;

        for(int right = 0; right < n; right++){
            sum = sum + arr[right];

            if(right - left + 1 == k){
                int len = right - left + 1; 
                if(sum/len >= threshold){
                    cnt++;
                }
                sum = sum - arr[left];
                left++;
            }
        }

        return cnt;
    }
};