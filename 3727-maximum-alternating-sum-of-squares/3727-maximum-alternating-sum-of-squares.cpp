class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int& x : nums)
            x = x * x;

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int mid = n / 2;
        
        for (int i = 0; i < mid; i++) {
            ans -= nums[i];
        }
        for (int i = mid; i < nums.size(); i++) {
            ans += nums[i];
        }
        return ans;
    }
};