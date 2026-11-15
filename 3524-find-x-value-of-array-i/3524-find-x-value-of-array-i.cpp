class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> nextdp(k, 0);
            int rem = x % k;
            nextdp[rem]++;

            for (int r = 0; r < k; r++) {
                int newrem = (r * rem) % k;
                nextdp[newrem] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += nextdp[r];
            }
            dp = nextdp;
        }
        return ans;
    }
};