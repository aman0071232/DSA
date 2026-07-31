class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int K = min(m - 1, n - 1);
        long long res = 1;

        for (int i = 1; i <= K; ++i) {
            res = res * (N - K + i) / i;
        }
        return(int) res;
    }
};