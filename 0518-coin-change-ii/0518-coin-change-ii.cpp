class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1);
        dp[0] = 1;
        for (int c : coins) {
            for (int i=c; i<=amount; ++i) {
                dp[i] += dp[i - c];
            }
        }
        return (int)dp[amount];
    }
};