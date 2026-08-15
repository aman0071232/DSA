class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_non_zero = false;

        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_non_zero = true;
            }
        }
        if (!has_non_zero) {
            return 0;
        }

        return (total_xor != 0) ? nums.size() : nums.size() - 1;
    }
};