class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i <= nums.size() - k; i++) {

            unordered_set<int> seen;
            for (int j = i; j < i + k; j++) {

                seen.insert(nums[j]);
            }
            for (int it : seen) {
                mp[it]++;
            }
        }
        int ans = -1;
        for (auto it : mp) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }
        return ans;
        ;
    }
};