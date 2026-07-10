class Solution {
public:
    bool binary(int row, vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (target > matrix[row][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (binary(mid, matrix, target)) {
                return true;
            } else if (target > matrix[mid][n - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};