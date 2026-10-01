class Solution {
public:
    int gardenlastpoint;
    map<pair<int, int>, int> mp;
    int solve(int i, int maxend, vector<pair<int, int>>& range) {
        if (i >= range.size()) {
            if (maxend >= gardenlastpoint) {
                return 0;
            } else {
                return 1e9;
            }
        }
        if (range[i].first > maxend) {
            return 1e9;
        }
        if (mp.find({i, maxend}) != mp.end()) {
            return mp[{i, maxend}];
        }
        int not_open = solve(i + 1, maxend, range);
        int open_tap = 1 + solve(i + 1, max(maxend, range[i].second), range);
        return mp[{i, maxend}] = min(not_open, open_tap);
    }
    int minTaps(int n, vector<int>& ranges) {
        gardenlastpoint = n;
        vector<pair<int, int>> range;
        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            range.push_back({start, end});
        }
        sort(begin(range), end(range));

        int result = solve(0, 0, range);
        return result == 1e9 ? -1 : result;
    }
};