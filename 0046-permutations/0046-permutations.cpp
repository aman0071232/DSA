class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;
    void solve(vector<int>& temp, vector<int>& nums) {
        int n = nums.size();
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);

                temp.push_back(nums[i]);
                solve(temp, nums);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(temp, nums);
        return result;
    }
};