class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>result(2*nums.size());
        int j=0;
        for(int i=0;i<2*nums.size();i++){
            result[i]=nums[j];
            j++;
            if(j>=nums.size()){
                j=0;
            }
        }
        return result;
    }
};