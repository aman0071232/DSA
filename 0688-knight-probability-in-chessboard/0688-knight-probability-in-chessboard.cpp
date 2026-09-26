class Solution {
public:
    int N;
    unordered_map<string, double> mp;

    vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    double solve(int r, int c, int k) {
        if (r < 0 || r >= N || c < 0 || c >= N) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        string key = to_string(k) + "_" + to_string(r) + "_" + to_string(c);

        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        double ans = 0;
        for (auto& dir : directions) {
            int new_r = r + dir.first;
            int new_c = c + dir.second;

            ans += (double)solve(new_r, new_c, k - 1);
        }
        return mp[key] = (double)ans / (8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        return solve(row, column, k);
    }
};