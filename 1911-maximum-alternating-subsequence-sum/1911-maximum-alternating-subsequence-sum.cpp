class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even=0,odd=0;

        for(int num:nums){
            long long newEven=max(even,odd+num);
            long long newOdd=max(odd,even-num);

            even=newEven;
            odd=newOdd;
        }
        return even;
    }
};