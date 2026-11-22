class Solution {
public:
    bool checkString(string s) {
        bool seenA = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                seenA = true;
            } else if (s[i] == 'a' && seenA) {
                return false;
            }
        }
        return true;
    }
};