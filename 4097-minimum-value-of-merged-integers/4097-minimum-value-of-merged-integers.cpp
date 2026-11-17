class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            int b = nums[i + 1];

            int power = 10;
            while (b >= 10) {
                power *= 10;
                b /= 10;
            }
            int merged = nums[i] * power;
            int temp = nums[i + 1];
            power = 10;
            while (temp >= 10) {
                power *= 10;
                temp /= 10;
            }
            merged = nums[i] * power + nums[i + 1];
            ans = min(ans, merged);
        }
        return ans;
    }
};