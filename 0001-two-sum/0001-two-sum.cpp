class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int sec = target - first;
            if (mp.find(sec) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[sec]);
                break;
            }
            mp[first] = i;
        }
        return ans;
    }
};