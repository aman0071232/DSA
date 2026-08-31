class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minindex = 0;
        int maxindex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]<nums[minindex]){
                minindex=i;
            }
            if(nums[i]>nums[maxindex]){
                maxindex=i;
            }
        }
        int left=min(maxindex,minindex);
        int right=max(minindex,maxindex);

        int removefromfront=right+1;
        int removefromback=nums.size()-left;

        int removebothside=(left+1)+(nums.size()-right);

        return min({removefromfront,removefromback,removebothside});
    }
};