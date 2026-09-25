class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][1] = -prices[0];
        dp[0][0] = 0;

        for (int i = 1; i < n; i++) {
            dp[i][1] = max(-prices[i] + dp[i - 1][0], dp[i - 1][1]);

            dp[i][0] = max(prices[i] - fee + dp[i - 1][1], dp[i - 1][0]);
        }
        return dp[n - 1][0];
    }
};