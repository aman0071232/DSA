class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int ans = 0;
        int target = k * threshold;
        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            if (right >= k) {
                sum -= arr[right - k];
            }
            if (right >= k - 1 && sum >= target) {
                ans++;
            }
        }
        return ans;
    }
};