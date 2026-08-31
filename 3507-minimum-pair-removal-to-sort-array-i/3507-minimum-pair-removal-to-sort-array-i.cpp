class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (true) {
            bool sorted = true;

            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                return operations;
            }
            int index = 0;
            for (int i = 1; i + 1 < nums.size(); i++) {
                if (nums[i] + nums[i + 1] < nums[index] + nums[index + 1]) {
                    index = i;
                }
            }
            nums[index] += nums[index + 1];

            nums.erase(nums.begin() + index + 1);
            operations++;
        }
    }
};