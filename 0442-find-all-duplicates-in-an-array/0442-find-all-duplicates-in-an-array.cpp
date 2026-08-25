class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> a;
        for (int i = 0; i < nums.size(); i++) {
                mp[nums[i]]+=1;
        }
        for(auto it: mp){
            if(it.second!=1){
                a.push_back(it.first);
            }
        }
        return a;
    }
};