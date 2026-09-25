class Solution {
public:
    int n;
    vector<vector<int>> t;
    vector<int> next;
    int solve(vector<vector<int>>& events, int idx, int k) {
        if (idx >= n || k == 0) {
            return 0;
        }
        if (t[idx][k] != -1)
            return t[idx][k];
        int start = events[idx][0];
        int end = events[idx][1];
        int value = events[idx][2];

        int skip = solve(events, idx + 1, k);

        int take = value + solve(events, next[idx], k - 1);

        return t[idx][k] = max(skip, take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        t.assign(n, vector<int>(k + 1, -1));
        next.resize(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] > events[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }
            next[i] = lo;
        }
        return solve(events, 0, k);
    }
};