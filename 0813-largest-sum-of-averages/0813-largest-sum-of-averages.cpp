class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(k + 1, vector<double>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[1][i] = prefix[i] / i;
        }
        for (int g = 2; g <= k; g++) {
            for (int i = g; i <= n; i++) {
                for (int j = g - 1; j < i; j++) {
                    double avg = (prefix[i] - prefix[j]) / (i - j);

                    dp[g][i] = max(dp[g][i], dp[g - 1][j] + avg);
                }
            }
        }
        return dp[k][n];
    }
};