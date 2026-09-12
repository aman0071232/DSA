class Solution {
public:
    int t[201][201];
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid[0].size();
        int m = grid.size();
        t[0][0] = grid[0][0];
        for (int col = 1; col < n; col++) {
            t[0][col] = grid[0][col] + t[0][col - 1];
        }
        for (int row = 1; row < m; row++) {
            t[row][0] = grid[row][0] + t[row - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[i][j] = grid[i][j] + min(t[i - 1][j], t[i][j - 1]);
            }
        }
        return t[m - 1][n - 1];
    }
};