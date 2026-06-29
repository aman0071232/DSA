class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long num = 0;

        // skip spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // check sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-')  sign = -1;
            i++;
        }

        // convert digits to number
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // check for overflow before multiply with sign
            if (num * sign > INT_MAX)
                return INT_MAX;
            if (num * sign < INT_MIN)
                return INT_MIN;

            i++;
        }

        // return final number
        return num * sign;
    }
};