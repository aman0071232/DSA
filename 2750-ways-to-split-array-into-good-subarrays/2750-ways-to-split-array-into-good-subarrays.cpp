class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        int prev = -1;
        int mod = 1e9 + 7;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (prev != -1) {
                    ans = (ans * (i - prev)) % mod;
                }
                prev = i;
            }
        }
        if (prev == -1)
            return 0;

        return ans;
    }
};