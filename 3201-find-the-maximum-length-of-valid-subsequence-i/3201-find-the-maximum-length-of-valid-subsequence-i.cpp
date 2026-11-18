class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        int alternate = 0;
        int last = -1;
        for (int x : nums) {
            int parity = x % 2;
            if (parity == 0)
                even++;
            else {
                odd++;
            }
            if (parity != last) {
                alternate++;
                last = parity;
            }
        }
        return max({even, odd, alternate});
    }
};