class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int pairsum = numbers[i] + numbers[j];
            if (pairsum < target) {
                i++;
            } else if (pairsum > target) {
                j--;
            } else if (pairsum == target) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }
        return ans;
    }
};