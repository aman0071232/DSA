class Solution {
public:
    int n;
   vector<vector<int>>t;
    int solve(string& s, int curr_index, int prev) {
        if (curr_index >= n)
            return 0;
        if (t[curr_index][prev] != -1) {
            return t[curr_index][prev];
        }
        int flip = INT_MAX;
        int no_flip = INT_MAX;

        if (s[curr_index] == '0') {
            if (prev == 0) {
                flip = 1 + solve(s, curr_index + 1, 1);
                no_flip = solve(s, curr_index + 1, 0);
            } else {
                flip = 1 + solve(s, curr_index + 1, 1);
            }
        } else if (s[curr_index] == '1') {
            if (prev == 0) {
                flip = 1 + solve(s, curr_index + 1, 0);
                no_flip = solve(s, curr_index + 1, 1);
            } else {
                no_flip = solve(s, curr_index + 1, 1);
            }
        }

        return t[curr_index][prev]= min(flip, no_flip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.length();
        t.assign(n,vector<int>(2,-1));
        return solve(s, 0, 0);
    }
};