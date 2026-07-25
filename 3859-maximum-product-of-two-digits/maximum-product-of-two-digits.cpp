class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while (n > 0) {
            int digit = n % 10;
            digits.push_back(digit);
            n = n / 10;
        }

        sort(digits.begin(), digits.end());
        int size = digits.size();

        int a = digits[size - 1];
        int b = digits[size - 2];

        return a * b;
    }
};