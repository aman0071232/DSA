class Solution {
public:

set<vector<int>>s;
void getAllCombination(vector<int>&arr,int idx,int tar,vector<vector<int>>&ans,vector<int>&combin){
    if(idx==arr.size() || tar<0){
        return ;
    }
    if(tar==0){
        if(s.find(combin)==s.end()){
            ans.push_back(combin);
            s.insert(combin);
        }
       
        return;
    }

    combin.push_back(arr[idx]);
    //single
  getAllCombination(arr,idx+1,tar-arr[idx],ans,combin);
  
  //multiple
    getAllCombination(arr,idx,tar-arr[idx],ans,combin);
    combin.pop_back();
     //exclusion
    getAllCombination(arr,idx+1,tar,ans,combin);
}
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>>ans;
        vector<int>combin;
          getAllCombination(arr,0,tar,ans,combin);
          return ans;
    }
};