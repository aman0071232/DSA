class Solution {
public:
    bool search(vector<int>& nums, int target) {
      bool a=false;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            a=true;
            break;
        }
      }  
      return a;
    }
};

