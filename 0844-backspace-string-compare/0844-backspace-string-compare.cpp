class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();

        int i = m - 1;
        int j = n - 1;
        int skip_s = 0;
        int skip_t = 0;

        while (i >= 0 || j > 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_s++;
                    i--;
                } else if (skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skip_t++;
                    j--;
                } else if (skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }
            char first = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];

            if (first != second)
                return false;

            i--;
            j--;
        }
        return true;
    }
};