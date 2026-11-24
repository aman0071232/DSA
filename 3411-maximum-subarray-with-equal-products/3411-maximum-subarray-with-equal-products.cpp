class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long prod = 1;
            int g = 0;
            int l = 1;
            for (int j = i; j < nums.size(); j++) {
                if (prod > LLONG_MAX / nums[j])
                    break;
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                long long temp = l / gcd(l, (long long)nums[j]);
                if (temp > LLONG_MAX / nums[j])
                    break;
                l = lcm(l, nums[j]);

                if (prod == 1LL * l * g) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};