class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int deletions = 0;
        int last = -1;
        for (int x : nums) {
            if (x == last)
                deletions++;
            else
                last = x;
        }
        return deletions;
    }
};