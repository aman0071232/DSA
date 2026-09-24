class Solution {
public:
   int n;
   int t[21][10003];
   int solve(vector<int>&rods,int idx,int diff){
    if(idx>=n){
        if(diff==0){
            return 0;
        }
        return INT_MIN;
    }
    if(t[idx][diff+5000]!=-1){
        return t[idx][diff+5000];
    }
    int nothing=solve(rods,idx+1,diff);
    int in_left_rod=rods[idx]+solve(rods,idx+1,diff+rods[idx]);

    int in_right_rod=rods[idx]+solve(rods,idx+1,diff-rods[idx]);
    return t[idx][diff+5000]=max({nothing,in_left_rod,in_right_rod});
   }
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        memset(t,-1,sizeof(t));
        return solve(rods,0,0)/2;
    }
};