class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);

        int ans=-1;

        for(int i=0;i<n;i++){

            if(vis[i])
            continue;

            unordered_map<int,int>dist;

            int node=i;
            int step=0;

            while(node!=-1 && !vis[node]){
                vis[node]=1;
                dist[node]=step++;

                node=edges[node];

                if(node!=-1 && dist.count(node)){
                    ans=max(ans,step-dist[node]);
                    break;
                }
            }
        }
        return ans;
    }
};