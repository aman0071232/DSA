class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return 1e9;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = 1e9;
        for (int coin : coins) {
            if (coin <= amount) {
                int result = 1 + solve(coins, amount - coin, dp);
                if (result != 1e9)
                    ans = min(ans, result);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};