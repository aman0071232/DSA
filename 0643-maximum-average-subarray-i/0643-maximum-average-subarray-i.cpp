class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0;i < k; i++) {
            sum += nums[i];
        }
        long long maxsum = sum;

        for (int right = k; right < nums.size(); right++) {
            sum += nums[right];
            sum -= nums[right - k];
            maxsum = max(maxsum, sum);
        }
        return static_cast<double>(maxsum) / k;
    }
};