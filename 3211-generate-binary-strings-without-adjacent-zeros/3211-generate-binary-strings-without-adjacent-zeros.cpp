class Solution {
public:
    vector<string> ans;
    void solve(string s, int n) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        solve(s + '1', n);

        if (s.empty() || s.back() != '0') {
            solve(s + '0', n);
            ;
        }
    }
    vector<string> validStrings(int n) {
        solve("", n);
        return ans;
    }
};