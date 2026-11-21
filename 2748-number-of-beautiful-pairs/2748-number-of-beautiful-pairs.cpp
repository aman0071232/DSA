class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];

            while (first >= 10) {
                first /= 10;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                int last = nums[j] % 10;

                if (__gcd(first, last) == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};