// A cycle of size (k) requires (k-1) swaps.
class Solution {
public:
    int solve(int a) {
        int sum = 0;

        while (a > 0) {
            sum += a % 10;
            a = a / 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [&](const auto& a, const auto& b) {
            if (solve(a.first) == solve(b.first)) {
                return a.first < b.first;
            } else {
                return solve(a.first) < solve(b.first);
            }
        });

        int swaps = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};