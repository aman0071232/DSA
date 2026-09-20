class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int st = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
              if(mp[nums[i]]==1){
                st=nums[i];
                break;
              }
        }
        return st;
    }
};