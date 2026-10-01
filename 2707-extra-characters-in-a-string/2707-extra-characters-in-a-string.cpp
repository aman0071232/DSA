class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[51];
    int solve(int idx, string& s) {
        if (idx >= n)
            return 0;
        if (t[idx] != -1) {
            return t[idx];
        }
        string currstr = "";
        int minextra = n;

        for (int i = idx; i < n; i++) {
            currstr.push_back(s[i]);
            int currextra =
                (st.find(currstr) == st.end()) ? currstr.length() : 0;
            int nextextra = solve(i + 1, s);
            int totalextra = currextra + nextextra;
            minextra = min(minextra, totalextra);
        }
        return t[idx] = minextra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        for (string& word : dictionary) {
            st.insert(word);
        }
        memset(t, -1, sizeof(t));
        return solve(0, s);
    }
};