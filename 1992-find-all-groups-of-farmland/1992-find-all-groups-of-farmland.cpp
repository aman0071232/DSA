class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1 &&(i==0 ||land[i-1][j]==0)&&(j==0 || land[i][j-1]==0)){

                    int x=i,y=j;

                    while(x+1 <m && land[x+1][j]==1) x++;
                    while(y+1<n && land[i][y+1]==1)y++;

                    ans.push_back({i,j,x,y});
                }
            }
        }
        return ans;
    }
};