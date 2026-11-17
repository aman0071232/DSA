class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long x = max(n, m);
        if (x <= k)
            return 0;
        return 1LL * k * (x - k);
    }
};