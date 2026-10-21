class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(36, 0);
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                freq[c - 'a']++;
            } else {
                freq[26 + (c - '0')]++;
            }
        }
        int ans = 0;

        for (int i = 0; i < 13; i++) {
            ans += abs(freq[i] - freq[25 - i]);
        }
        for (int i = 0; i < 5; i++) {
            ans += abs(freq[26 + i] - freq[26 + 9 - i]);
        }
        return ans;
    }
};