class Solution {
public:
    bool check(int speed, int h, vector<int>& piles) {
        long long totalTime = 0;

        for (int bananas : piles) {
            totalTime += (bananas + speed - 1) / speed;
        }

        return totalTime <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(mid, h, piles))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};