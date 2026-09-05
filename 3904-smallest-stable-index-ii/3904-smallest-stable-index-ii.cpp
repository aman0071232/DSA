class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixmin(n);

        suffixmin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixmin[i] = min(nums[i], suffixmin[i + 1]);
        }
        int prefixmax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixmax = max(prefixmax, nums[i]);

            long long instability = prefixmax - suffixmin[i];

            if (instability <= k)
                return i;
        }
        return -1;
    }
};