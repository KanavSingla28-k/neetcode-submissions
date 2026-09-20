class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for (auto& p: pre){
            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
        }

        return !detect(adj, n);
    }

    bool detect(vector<vector<int>>& adj, int n){
        vector<bool> vis(n, false);
        vector<bool> parent(n, false);

        bool cycle = false;

        for (int i = 0; i<n; i++){
            if (!vis[i]){
                if (dfs(i, vis, adj, parent)) cycle = true;
            }
        }
        return cycle;
    }

    bool dfs(int u, vector<bool> &vis, vector<vector<int>>& adj, vector<bool>& par){
        vis[u] = true;
        par[u] = true;

        for (int v: adj[u]){
            if (!vis[v]){
                if (dfs(v, vis, adj, par)) return true;
            }
            else if (par[v]) return true;
        }
        par[u] = false;
        return false;
    }

};
