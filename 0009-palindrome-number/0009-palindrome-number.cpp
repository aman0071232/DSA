class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        int revnum = 0;

        while (x > 0) {
            int ld = x % 10;
            if (revnum >= INT_MAX / 10 || revnum <= INT_MIN / 10) {
                return 0;
            }
            revnum = revnum * 10 + ld;
            x = x / 10;
        }
        return revnum == original;
    }
};