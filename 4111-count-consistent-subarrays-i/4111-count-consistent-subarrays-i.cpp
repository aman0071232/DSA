class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int mn = nums[i];
            for (int j = i; j < nums.size(); j++) {
                x &= nums[j];
                mn = min(mn, nums[j]);
                if (x == mn) {
                    ans++;
                }
            }
        }
        return ans;
    }
};