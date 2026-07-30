class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;

        for (auto it : gifts) {
            pq.push(it);
        }
        while (k--) {
            int gift = pq.top();
            pq.pop();

            int newGift = sqrt(gift);
            pq.push(newGift);
        }
        
        while (!pq.empty()) {
            sum = sum + pq.top();
            pq.pop();
        }
        return sum;
    }
};