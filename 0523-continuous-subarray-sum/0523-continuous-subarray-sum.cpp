class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> firstindex;
        firstindex[0] = -1;
        long long prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            long long key;
            if (k == 0) {
                key = prefix;
            } else {
                key = prefix % abs((long long)k);
            }
            if (firstindex.count(key)) {
                if (i - firstindex[key] >= 2) {
                    return true;
                }
            } else {
                firstindex[key] = i;
            }
        }
        return false;
    }
};