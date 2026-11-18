class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int ans = 0;
        int end = -1;
        for (auto& p : points) {
            int x = p[0];

            if (x > end) {
                ans++;
                end = x + w;
            }
        }
        return ans;
    }
};