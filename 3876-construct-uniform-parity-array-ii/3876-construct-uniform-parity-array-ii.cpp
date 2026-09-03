class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        vector<int> nums2(nums1.size(), 0);
        if (nums1.size() < 2)
            return true;
        int j = 0;
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] < nums1[j]) {
                j = i;
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (j != i) {
                nums2[i] = nums1[i] - nums1[j];
            }
        }
        bool isodd = false;
        for (int x : nums2) {
            if (x % 2 != 0) {
                isodd = true;
                break;
            }
        }
        if(!isodd){
            return true;
        }
        return (nums1[j]%2!=0);
    }
};