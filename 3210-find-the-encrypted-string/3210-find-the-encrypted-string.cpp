class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += s[(i + k) % n];
        }
        return ans;
    }
};