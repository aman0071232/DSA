class Solution {
public:
vector<int>parent;

int find(int x){
    if(parent[x]==x)
    return x;
    return parent[x]=find(parent[x]);
}
bool unite(int u,int v){
    int pu=find(u);
    int pv=find(v);

    if(pu==pv)
    return false;

    parent[pv]=pu;
    return true;

}
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>indegree(n+1,0);
        vector<int>cand1,cand2;

        for(auto&e:edges){
            int u=e[0];
            int v=e[1];

            if(indegree[v]==0){
            indegree[v]=u;
            }else{
                cand1={indegree[v],v};
                cand2={u,v};
                e[1]=0;
            }
        }
        parent.resize(n+1);

        for(int i=0;i<=n;i++)
            parent[i]=i;
            for(auto&e:edges){

                if(e[1]==0)
                continue;

                int u=e[0];
                int v=e[1];

                if(!unite(u,v)){
                    if(cand1.empty())
                    return e;

                    return cand1;
                }
            }
            return cand2;
        
    }
};