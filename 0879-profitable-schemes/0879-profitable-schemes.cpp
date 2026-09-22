class Solution {
public:
    int N;
    int t[101][101][101];
    const int MOD =1e9+7;
    int solve(int i, int p, int people, int& minProfit, vector<int>& group,
              vector<int>& profit) {
        if (people > N)
            return 0;

        if (i == group.size()) {
            if (p >= minProfit)
                return t[i][p][people]=1;

             return t[i][p][people]= 0;
        }
        if (t[i][p][people] != -1)
            return t[i][p][people];
        long long not_taken =
            solve(i + 1, p, people, minProfit, group, profit);
        long long taken = solve(i + 1, min(p + profit[i], minProfit),
                                people + group[i], minProfit, group, profit) ;
                          

        return t[i][p][people]= (not_taken + taken) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        N = n;
        memset(t,-1,sizeof(t));
        return solve(0, 0, 0, minProfit, group, profit);
    }
};