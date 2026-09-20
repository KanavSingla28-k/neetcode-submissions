class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i<n; i++){
            if (!vis[i]){
                dfs(i, vis, adj);
                cnt++;
            }
        }

        return cnt;
    }

    void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj){
        vis[u] = true;

        for (int v: adj[u]){
            if (!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
};
