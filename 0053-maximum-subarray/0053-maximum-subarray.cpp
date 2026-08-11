class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxi = INT_MIN;
        for (int num : nums) {
            currsum += num;
            maxi = max(maxi, currsum);
            if (currsum < 0)
                currsum = 0;
        }
        return maxi;
    }
};