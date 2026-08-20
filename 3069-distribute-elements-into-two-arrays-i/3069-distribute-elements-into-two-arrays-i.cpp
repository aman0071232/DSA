class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        unordered_set<int> st;
        vector<int> res;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int idx = 3;
        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        for(int n:arr1){
            res.push_back(n);
        }
        for(int n:arr2){
            res.push_back(n);
        }
        return res;
    }
};