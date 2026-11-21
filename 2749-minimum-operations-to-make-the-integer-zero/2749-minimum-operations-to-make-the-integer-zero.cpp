class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; i <= 60; i++) {
            long long x = (long long)num1 - (long long)i * num2;

            if (x < i)
                continue;

            if (__builtin_popcountll(x) <= i) {
                return i;
            }
        }
        return -1;
    }
};