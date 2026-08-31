class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double half = myPow(x, N / 2);
        if (N % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};