class Solution {
public:
    bool issubsequence(string a, string b) {
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (string word : dictionary) {
            if (issubsequence(word, s)) {
                if (word.size() > ans.size()) {
                    ans = word;
                } else if (word.size() == ans.size() && word < ans) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};