class Solution {
public:
    string resultingString(string s) {
        string st = "";
        for (char c : s) {
            if (!st.empty() &&
                (abs(c - st.back()) == 1 || abs(c - st.back()) == 25)) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st;
    }
};