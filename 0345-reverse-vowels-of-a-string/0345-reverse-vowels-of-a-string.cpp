class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'o' ||
               c == 'O' || c == 'e' || c == 'E' || c == 'u' || c == 'U';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isvowel(s[i])) {
                i++;
            }
            while (i < j && !isvowel(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};