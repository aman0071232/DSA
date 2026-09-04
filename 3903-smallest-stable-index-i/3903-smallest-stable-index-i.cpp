class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                int maxValue = *max_element(nums.begin(), nums.begin() + i + 1);
                int minValue = *min_element(nums.begin() + i, nums.end());
                int instable = maxValue - minValue;

                if(instable<=k)return i;
            }
        }
        return -1;
    }
};