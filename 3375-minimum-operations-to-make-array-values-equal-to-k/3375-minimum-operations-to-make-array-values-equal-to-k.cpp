class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for (int x : nums) {
            if (x < k)
                return -1;

            if (x > k) {
                st.insert(x);
            }
        }
        return st.size();
    }
};