class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> order, freq;
            int ok = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (!order.count(x)) {
                    order[x] = order.size() + 1;
                }
                freq[x]++;
                if (freq[x] > order[x]) {
                    break;
                }
                if (freq[x] == order[x]) {
                    ok++;

                    if (ok == order.size()) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};