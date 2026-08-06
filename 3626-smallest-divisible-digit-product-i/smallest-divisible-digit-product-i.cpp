class Solution {
public:
    int f(int n) {
        int prod = 1;
        while (n > 0) {
            prod = prod * (n % 10);
            n = n / 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            if (f(n) % t == 0) {
                return n;
            }
            n++;
        }
        return -1;
    }
};