class Solution {
public:
    int maxProduct(int n) {
        int maxi = INT_MIN;
        int smaxi = INT_MIN;

        while (n > 0) {
            int digit = n % 10;

            if (digit > maxi) {
                smaxi = maxi;
                maxi = digit;
            }
            else if (digit >= smaxi) {
                smaxi = digit;
            }

            n /= 10;
        }

        return maxi * smaxi;
    }
};