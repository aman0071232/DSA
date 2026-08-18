class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long expectedSum=(long long)n*(n+1)/2;
        long long actualSum=0;

        for(int x:nums) actualSum+=x;

        return expectedSum-actualSum;
    }
};