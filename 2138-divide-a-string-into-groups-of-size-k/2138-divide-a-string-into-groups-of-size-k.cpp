class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        int j = 0;
        vector<string> vec;
        while (j < s.size()) {
            string ans = "";
            for (int i = 0; i < k; i++) {
                if (j < s.size())
                    ans += s[j++];
                else
                    ans += fill;
            }
            vec.push_back(ans);
        }
        return vec;
    }
};