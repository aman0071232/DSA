class Solution {
public:
    bool issubsequence(string a, string b) {
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        int maxi = -1;

        for (int i = 0; i < strs.size(); i++) {
            bool uncommon = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && issubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if (uncommon) {
                maxi = max(maxi, (int)strs[i].size());
            }
        }
        return maxi;
    }
};