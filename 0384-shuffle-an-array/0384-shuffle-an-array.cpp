class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) { original = nums; }

    vector<int> reset() { return original; }

    vector<int> shuffle() {
        vector<int> arr = original;

        for (int i = arr.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */