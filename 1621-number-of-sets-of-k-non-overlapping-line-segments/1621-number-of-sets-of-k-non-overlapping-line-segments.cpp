class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];
    int numberOfSets(int n, int K) {
        for (int i = 0; i <= n - 1; i++) {
            dp[0][i] = 1;
        }
        for (int k = 1; k <= K; k++) {
            vector<int> prevrowsum(n + 1, 0);
            for (int x = n - 1; x >= 0; x--) {
                prevrowsum[x] = (prevrowsum[x + 1] + dp[k - 1][x]) % M;
            }
            for (int i = n - 1; i >= 0; i--) {
                int take = prevrowsum[i + 1];
                int skip = dp[k][i + 1] % M;
                dp[k][i] = (take + skip) % M;
            }
        }
        return dp[K][0];
    }
};