class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            if (x == 2) {
                ans.push_back(-1);
                continue;
            }
            int bit = 1;
            while (x & bit) {
                bit <<= 1;
            }
            ans.push_back(x - (bit >> 1));
        }
        return ans;
    }
};