class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        vector<int>& sorting = source;
        long long sum1 = 0;
        long long sum2 = 0;
        for (int num : sorting)
            sum1 += num;
        for (int num : target)
            sum2 += num;
        return sum1 == sum2;
    }
};