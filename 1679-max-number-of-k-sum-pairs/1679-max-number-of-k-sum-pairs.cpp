class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0;
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int count=0;
        while(i<j){
            int pair=nums[i]+nums[j];
            if(pair==k){
                i++;
                j--;
                count++;
            }
            else if(pair>k){
                j--;
            }
            else{
                i++;
            }
        }
        return count;
    }
};