class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n)
                continue;
            
                count[nums[i]]++;
        }
        for (int i = 1; i <=n; i++) {
            if (count[i] == 0)
                return i;
        }
        return n+1;
    }
};