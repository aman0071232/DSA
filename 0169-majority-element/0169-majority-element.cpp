class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int cand=nums[0];
        for(int num:nums){
            if(count==0){
                cand=num;
            }
            if(num==cand)count++;
            else count--;
        }
        int freq=0;
        for(int num:nums){
            freq++;
        }if(freq>nums.size()/2)
        return cand;

        return -1;
    }
};