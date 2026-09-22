class Solution {
public:
int n;
int t[1001][2001];
int solve(int i,vector<vector<int>>&piles,int k){
    if(i>=n)return 0;
    if(t[i][k]!=-1)return t[i][k];
    int not_taken=solve(i+1,piles,k);
    int taken=0;
    int sum=0;
    for(int j=0;j<min(k,(int)piles[i].size());j++){
        sum+=piles[i][j];
        taken=max(taken,sum+solve(i+1,piles,k-(j+1)));

    }
    return t[i][k]=max(taken,not_taken);    
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        return solve(0,piles,k);
    }
};