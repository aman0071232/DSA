class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx=0;
        for (int n : nums) {
            nums[idx++]=n*n;
        }
        sort(nums.begin(),nums.end());
        return nums;
        
    }
};