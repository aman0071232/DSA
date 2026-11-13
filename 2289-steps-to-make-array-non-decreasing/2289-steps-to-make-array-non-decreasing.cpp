class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> st;

        int ans = 0;
        for (int x : nums) {
            int steps = 0;

            while (!st.empty() && st.top().first <= x) {
                steps = max(steps, st.top().second);
                st.pop();
            }
            if (!st.empty()) {
                steps++;
            } else {
                steps = 0;
            }
            ans = max(ans, steps);
            st.push({x, steps});
        }
        return ans;
    }
};