class Solution {
public:
    long long findSum(int n) {
        long long sum = 0;
        while (n > 0) {
            sum = sum + (n % 10);
            n = n / 10;
        }
        return sum;
    }
    long long findProduct(int n) {
        long long product = 1;
        while (n > 0) {
            product = product * (n % 10);
            n = n / 10;
        }
        return product;
    }

    bool checkDivisibility(int n) {
        if (n % (findSum(n) + findProduct(n)) == 0) {
            return true;
        }
        return false;
    }
};