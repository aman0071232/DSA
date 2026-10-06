class Solution {
public:
    int n;
    unordered_map<string,int>mp;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, vector<bool>& used,
              string& state) {
        if (i == n)
            return 0;

        if (mp.find(state) != mp.end())
            return mp[state];
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (used[j])
                continue;

            used[j] = true;
            state[j] = '1';
            int cost =
                (nums1[i] ^ nums2[j]) + solve(nums1, nums2, i + 1, used, state);
            ans = min(ans, cost);
            used[j] = false;
            state[j] = '0';
        }
        return mp[state] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        vector<bool> used(n, false);
        string state(n, '0');
        return solve(nums1, nums2, 0, used,state);
    }
};