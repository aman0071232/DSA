class Solution {
public:
    vector < vector< int >> ans;
    vector<int> tin, low, vis;
    int timer = 1;

    void dfs(int node, int parent, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent)
                continue;

            if (!vis[it]) {
                dfs(it, node, adj);

                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    ans.push_back({node, it});
                }

            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> adj[n];

        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        tin.resize(n);
        low.resize(n);
        vis.resize(n, 0);

        dfs(0, -1, adj);

        return ans;
    }
};