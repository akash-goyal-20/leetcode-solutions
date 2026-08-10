class Solution {
public:
    int solveForAlice(int index, int person, vector<int>& stones,
                      vector<vector<int>>& dp) {
        int n = stones.size();
        if (index >= n) {
            return 0;
        }
        if (dp[index][person] != -1) {
            return dp[index][person];
        }
        int result = (person == 1) ? INT_MIN : INT_MAX;
        int totalStones = 0;

        for (int i = index; i < min(index + 3, n); i++) {
            totalStones = totalStones + stones[i];
            if (person == 1) {
                result = max(result,
                             totalStones + solveForAlice(i + 1, 0, stones, dp));
            } else {
                result = min(result, solveForAlice(i + 1, 1, stones, dp));
            }
        }

        return dp[index][person] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sumStones = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2, -1));

        int aliceScore = solveForAlice(0, 1, stoneValue, dp);
        int bobScore = sumStones - aliceScore;

        if (aliceScore > bobScore) {
            return "Alice";
        } else if (aliceScore == bobScore) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};