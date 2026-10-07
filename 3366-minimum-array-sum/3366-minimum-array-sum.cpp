class Solution {
public:
    int n;
    int t[101][101][101];
    int solve(vector<int>& nums, int k, int i, int op1, int op2) {
        // base case
        if (i >= n) {
            return 0;
        }
        if (t[i][op1][op2]!=-1) {
            return t[i][op1][op2];
        }
        int result = INT_MAX;
        if (op1 > 0) {
            int newVal = (nums[i] + 1) / 2;
            int applyop1 = newVal + solve(nums, k, i + 1, op1 - 1, op2);
            result = min(result, applyop1);
        }
        if (op2 > 0 && nums[i] >= k) {
            int newVal = nums[i] - k;
            int applyop2 = newVal + solve(nums, k, i + 1, op1, op2 - 1);
            result = min(result, applyop2);
        }

        // op1->op2---case1
        // op2->op1---case2
        if (op1 > 0 && op2 > 0) {
            int newVal = (nums[i] + 1) / 2; // appply op1

            if (newVal >= k) {
                newVal = newVal - k; // apply op2
                int applyop1op2 =
                    newVal + solve(nums, k, i + 1, op1 - 1, op2 - 1);
                result = min(result, applyop1op2);
            }
            if (nums[i] >= k) { // apply op2
                newVal = nums[i] - k;
                newVal = (newVal + 1) / 2; // apply op1
                int applyop2op1 =
                    newVal + solve(nums, k, i + 1, op1 - 1, op2 - 1);
                result = min(result, applyop2op1);
            }
        }
        // applying no operation at nums[i]
        result = min(result, nums[i] + solve(nums, k, i + 1, op1, op2));

        return t[i][op1][op2] = result;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, k, 0, op1, op2);
    }
};