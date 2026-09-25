class Solution {
public:
    vector<int> dp, cnt;
    int solve(int i, vector<int>& nums) {
        if (dp[i] != -1)
            return dp[i];

        dp[i] = 1;
        cnt[i] = 1;

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                int len = 1 + solve(j, nums);
                if (len > dp[i]) {
                    dp[i] = len;
                    cnt[i] = cnt[j];
                } else if (len == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        return dp[i];
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        cnt.assign(n, -1);
        int maxlen = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int len = solve(i, nums);
            maxlen = max(maxlen, len);
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxlen)
                ans += cnt[i];
        }
        return ans;
    }
};