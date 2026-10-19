class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long even = 0;
        long long odd = LLONG_MIN;
        for (int x : nums) {
            long long newEven = max(even + x, odd + (x ^ k));

            long long newOdd = max(odd + x, even + (x ^ k));

            even = newEven;
            odd = newOdd;
        }
        return even;
    }
};