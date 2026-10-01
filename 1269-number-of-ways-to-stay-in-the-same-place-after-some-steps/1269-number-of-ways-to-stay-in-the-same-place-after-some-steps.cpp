class Solution {
public:
    int n;
    int t[501][501];
    const int MOD = 1e9 + 7;
    int solve(int idx, int steps) {
        if (idx < 0 || idx >= n)
            return 0;

        if (steps == 0)
            return idx == 0;

        if (t[idx][steps] != -1)
            return t[idx][steps];

        int result = solve(idx + 1, steps - 1);              // right
        result = (result + solve(idx - 1, steps - 1)) % MOD; // left
        result = (result + solve(idx, steps - 1)) % MOD;     // stay
        return t[idx][steps] = result;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        n = arrLen;
        memset(t, -1, sizeof(t));
        return solve(0, steps);
    }
};