class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int m = words.size();
        int len = words[0].size();

        unordered_map<string, int> mp;

        for (auto word : words) {
            mp[word]++;
        }
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> seen;

            int left = i;
            int count = 0;

            for (int j = i; j + len <= n; j += len) {
                string word = s.substr(j, len);

                if (mp.find(word) != mp.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > mp[word]) {
                        string temp = s.substr(left, len);

                        seen[temp]--;
                        count--;
                        left += len;
                    }
                    if (count == m) {
                        ans.push_back(left);

                        string temp = s.substr(left, len);

                        seen[temp]--;
                        count--;
                        left += len;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return ans;
    }
};