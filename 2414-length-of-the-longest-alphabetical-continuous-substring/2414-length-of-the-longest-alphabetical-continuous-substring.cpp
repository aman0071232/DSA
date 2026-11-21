class Solution {
public:
    int longestContinuousSubstring(string s) {
        int length = 1;
        int maxi = INT_MIN;
        if (s.size() == 1)
            return 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) {
                length++;
            } else {
                length = 1;
            }
            maxi = max(maxi, length);
        }
        return maxi;
    }
};