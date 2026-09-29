class Solution {
public:
    vector<string> ans;
    void solve(string digits, int idx, string temp, vector<string>& mp) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[idx] - '0'];
        for (char ch : letters) {
            temp.push_back(ch);

            solve(digits, idx + 1, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, 0, "", mp);
        return ans;
    }
};