class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            int ld = 0;
            int sum = 0;
            while (n != 0) {
                ld = n % 10;
                sum += ld;
                n = n / 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};