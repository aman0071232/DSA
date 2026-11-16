class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxsum = nums[0], minsum = nums[0];
        int curmax = 0, curmin = 0;
        for (int x : nums) {
            curmax = max(x, curmax + x);
            maxsum = max(maxsum, curmax);
            curmin = min(x, curmin + x);
            minsum = min(minsum, curmin);

            total += x;
        }
        if (maxsum < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};