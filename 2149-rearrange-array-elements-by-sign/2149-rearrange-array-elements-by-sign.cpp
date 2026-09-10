class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int posindex=0;
        int negindex=1;
        vector<int>ans(n,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans[negindex]=nums[i];
                negindex+=2;
            }
            else if(nums[i]>=0){
                ans[posindex]=nums[i];
                posindex+=2;
            }
        }
        return ans;
    }
};