class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> t;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR",
                         "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    int solve(int n, int prev) {
        if (n == 0)
            return 1;
        int result = 0;
        string last = states[prev];
        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev)
                continue;

            if (t[n][prev] != -1) {
                return t[n][prev];
            }

            string currPat = states[curr];
            bool conflict = false;
            for (int col = 0; col < 3; col++) {
                if (currPat[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                result = (result + solve(n - 1, curr)) % MOD;
            }
        }
        return t[n][prev] = result;
    }
    int numOfWays(int n) {
        t.resize(n,vector<int>(12, -1));
        int result = 0;
        for (int i = 0; i < 12; i++) {
            result = (result + solve(n - 1, i)) % MOD;
        }
        return result;
    }
};