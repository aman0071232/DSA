class Solution {
public:
    long long calculateScore(string s) {
        vector<stack<int>> st(26);
        long long score = 0;

        for (int i = 0; i < s.size(); i++) {
            int mirror = 25 - (s[i] - 'a');

            if (!st[mirror].empty()) {
                int j = st[mirror].top();
                st[mirror].pop();

                score += i - j;
            } else {
                st[s[i] - 'a'].push(i);
            }
        }
        return score;
    }
};