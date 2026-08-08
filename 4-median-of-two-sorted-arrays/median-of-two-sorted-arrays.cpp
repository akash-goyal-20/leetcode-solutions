class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

        int n1 = a.size();
        int n2 = b.size();

        // Always binary search on the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(b, a);
        }

        int low = 0;
        int high = n1;

        // Number of elements that should be on the left side
        int left = (n1 + n2 + 1) / 2;

        int n = n1 + n2;

        while (low <= high) {

            // Partition of array a
            int mid1 = (low + high) >> 1;

            // Partition of array b
            int mid2 = left - mid1;

            // Boundary values
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            // Right side of a
            if (mid1 < n1) {
                r1 = a[mid1];
            }

            // Right side of b
            if (mid2 < n2) {
                r2 = b[mid2];
            }

            // Left side of a
            if (mid1 - 1 >= 0) {
                l1 = a[mid1 - 1];
            }

            // Left side of b
            if (mid2 - 1 >= 0) {
                l2 = b[mid2 - 1];
            }

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Total number of elements is odd
                if (n % 2 == 1) {
                    return max(l1, l2);
                }

                // Total number of elements is even
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // Too many elements taken from a
            else if (l1 > r2) {
                high = mid1 - 1;
            }

            // Too few elements taken from a
            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};