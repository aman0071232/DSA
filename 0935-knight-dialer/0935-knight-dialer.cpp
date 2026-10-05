class Solution {
public:
    const int MOD = 1e9 + 7;
    int t[10][5001];

    vector<vector<int>> moves = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                 {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int solve(int curr, int remaining) {
        if (remaining == 1) {
            return 1;
        }
        if (t[curr][remaining] != -1) {
            return t[curr][remaining];
        }
        long long ways = 0;

        for (int next : moves[curr]) {
            ways += solve(next, remaining - 1);
            ways %= MOD;
        }
        return t[curr][remaining] = ways;
    }
    int knightDialer(int n) {
        memset(t, -1, sizeof(t));
        long long ans = 0;

        for (int digit = 0; digit <= 9; digit++) {
            ans += solve(digit, n);
            ans %= MOD;
        }
        return ans;
    }
};