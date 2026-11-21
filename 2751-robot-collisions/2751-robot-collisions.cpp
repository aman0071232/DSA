class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(),
             [&](int a, int b) { return positions[a] < positions[b]; });
        stack<int> st;
        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && directions[st.top()] == 'R' &&
                       healths[i] > 0) {
                    if (healths[st.top()] < healths[i]) {
                        healths[st.top()] = 0;
                        healths[i]--;
                        st.pop();
                    } else if (healths[st.top()] > healths[i]) {
                        healths[st.top()]--;
                        healths[i] = 0;
                    } else {
                        healths[st.top()] = 0;
                        healths[i] = 0;
                        st.pop();
                    }
                }
                if (healths[i] > 0) {
                    st.push(i);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};