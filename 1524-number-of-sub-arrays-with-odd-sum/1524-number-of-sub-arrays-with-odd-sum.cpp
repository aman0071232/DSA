class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 0;
        long long ans = 0;

        for (int x : arr) {
            if (x % 2 != 0) {
                long long temp = odd;
                odd = (even + 1) % MOD;
                even = temp;
            } else {
                even = (even + 1) % MOD;
            }
            ans = (ans + odd) % MOD;
        }
        return ans;
    }
};