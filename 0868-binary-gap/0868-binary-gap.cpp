class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int pos = 0;
        int maxi = 0;

        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    maxi = max(maxi, pos - prev);
                }
                prev = pos;
            }
            pos++;
            n = n >> 1;
        }
        return maxi;
    }
};