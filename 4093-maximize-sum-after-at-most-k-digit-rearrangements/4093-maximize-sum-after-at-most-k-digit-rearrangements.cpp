class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<int> gain;
        long long sum = 0;
        for (int x : nums) {
            sum += x;
            string s = to_string(x);
            sort(s.rbegin(), s.rend());
            int largest = stoi(s);
            gain.push_back(largest - x);
        }
        sort(gain.rbegin(), gain.rend());
        for (int i = 0; i < k; i++) {
            sum += gain[i];
        }
        return sum;
    }
};