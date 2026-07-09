class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        for (int x : arr)
            total += x;

        if (total % 3 != 0)
            return false;

        int target = total / 3;
        int sum = 0;
        int cnt = 0;

        for (int x : arr) {
            sum += x;
            if (sum == target) {
                cnt++;
                sum = 0;
            }
        }

        return cnt >= 3;
    }
};