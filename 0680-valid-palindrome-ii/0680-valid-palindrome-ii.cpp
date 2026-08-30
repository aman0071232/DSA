class Solution {
public:
    bool validPalindrome(string s) {
        int k = 1;
        int n = s.size();
        int i = 0;
        int j = n - 1;

        int i_save=-1;
        int j_save=-1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else if (s[i] != s[j] && k == 1) {
                i_save = i;
                j_save = j - 1;
                k--;
                i++;
            } else if (s[i] != s[j] && k == 0) {
                if (i_save != -1) {
                    i = i_save;
                    j = j_save;
                    i_save = -1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};