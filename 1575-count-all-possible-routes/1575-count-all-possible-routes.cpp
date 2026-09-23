class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    int t[101][201];
    int solve(vector<int>& locations, int i, int finish, int fuel) {
        if (fuel < 0) {
            return 0;
        }
        if (t[i][fuel] != -1) {
           return t[i][fuel];
        }
        int ans = 0;
        if (i == finish) {
            ans = 1;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int remaining_fuel = fuel - abs(locations[i] - locations[j]);
                ans = (ans + solve(locations, j, finish, remaining_fuel)) % MOD;
            }
        }
        return t[i][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(t, -1, sizeof(t));
        return solve(locations, start, finish, fuel);
    }
};