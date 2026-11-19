class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        vector<int> dp(1 << n, -1);

        function<int(int)> solve = [&](int mask) -> int {
            if (mask == (1 << n) - 1)
                return 0;
            if (dp[mask] != -1)
                return dp[mask];

            int count = __builtin_popcount(mask);
            int x = 1 + count * k;

            int ans = INT_MAX;

            for (int i = 0; i < n; i++) {

                if ((mask & (1 << i)) == 0) {
                    int time = (strength[i] + x - 1) / x;
                    int next = mask | (1 << i);
                    ans = min(ans, time + solve(next));
                }
            }
            return dp[mask] = ans;
        };
        return solve(0);
    }
};