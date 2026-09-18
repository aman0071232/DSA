class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>pos;

        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
        }
        for(const auto& op:operations){
            int oldval=op[0];
            int newval=op[1];

            int idx=pos[oldval];
            nums[idx]=newval;
            pos[newval]=idx;
        }
        return nums;
    }
};