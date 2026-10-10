class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merge;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merge.push_back(nums1[i++]);
            } else {
                merge.push_back(nums2[j++]);
            }
        }
        while (i < m)
            merge.push_back(nums1[i++]);
        while (j < n)
            merge.push_back(nums2[j++]);

        for (int k = 0; k < m + n; k++) {
            nums1[k] = merge[k];
        }
    }
};