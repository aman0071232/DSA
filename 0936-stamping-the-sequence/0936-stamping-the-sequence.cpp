class Solution {
public:
    bool canreplace(string& stamp, string& target, int start) {
        bool changed = false;
        for (int i = 0; i < stamp.size(); i++) {
            if (target[start + i] == '?')
                continue;

            if (target[start + i] != stamp[i]) {
                return false;
            }
            changed = true;
        }
        return changed;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();

        vector<int> ans;
        vector<bool> done(n, false);
        int count = 0;

        while (count < n) {
            bool found = false;
            for (int i = 0; i <= n - m; i++) {
                if (done[i])
                    continue;

                if (canreplace(stamp, target, i)) {
                    found = true;
                    ans.push_back(i);

                    for (int j = 0; j < m; j++) {
                        if (target[i + j] != '?') {
                            target[i + j] = '?';
                            count++;
                        }
                    }
                    done[i] = true;
                }
            }
            if (!found) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};