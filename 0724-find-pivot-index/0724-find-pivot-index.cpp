class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int i:nums){
            total+=i;
        }
        int leftsum=0;
        for(int i=0;i<nums.size();i++){
            total-=nums[i];

            if(total==leftsum)
            return i;

         leftsum+=nums[i];
        }
        return -1;
    }
};