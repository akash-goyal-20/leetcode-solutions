class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto it : nums) pq.push(it);

        int j = pq.top();
        pq.pop();
        int i = pq.top();
        int ans = (i-1)*(j-1);
        
        return ans;
    }
};