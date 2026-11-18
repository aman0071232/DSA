class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> count;
        int maxfreq = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int oldfreq = freq[x];
            if (oldfreq > 0) {
                count[oldfreq]--;
            }
            freq[x]++;
            int newfreq = freq[x];

            count[newfreq]++;
            maxfreq = max(maxfreq, newfreq);
            int n = i + 1;

            if (maxfreq == 1 || maxfreq * count[maxfreq] == n - 1 ||
                (maxfreq - 1) * (count[maxfreq - 1] + 1) == n - 1 &&
                    count[maxfreq] == 1) {
                ans = n;
            }
        }
        return ans;
    }
};