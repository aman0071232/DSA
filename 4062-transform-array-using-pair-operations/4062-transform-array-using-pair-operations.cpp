class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum1=0;
        long long sum2=0;
        for(int num:source)sum1+=num;
        for(int num:target)sum2+=num;
        return sum1==sum2;
    }
};