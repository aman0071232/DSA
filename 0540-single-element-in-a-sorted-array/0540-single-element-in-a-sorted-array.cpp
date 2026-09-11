class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int n = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (mid == 0 && nums[1] != nums[0])
                return nums[mid];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[n - 1];
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid - 1]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return nums[start];
    }
};