class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for (auto& p: pre){
            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
        }

        vector<int> ans;

        bool cyc = false;
        if (detect(adj, n)) cyc = true;
        if (cyc) return ans;

        return topological(adj, n);       
    }

    bool detect(vector<vector<int>>& adj, int n){
        vector<bool> vis(n, false);
        vector<bool> par(n, false);

        for (int i = 0; i<n; i++){
            if (!vis[i]){
                if (cycle(i, vis, adj, par)) return true;
            }
        }
        return false;

    }

    bool cycle(int u, vector<bool>& vis, vector<vector<int>>& adj, vector<bool>& par){
        vis[u] = true;
        par[u] = true;

        for (int v: adj[u]){
            if (!vis[v]){
                if (cycle(v, vis, adj, par)) return true;
            }
            else if (par[v]) return true;
        }

        par[u] = false;
        return false;
    }

    vector<int> topological(vector<vector<int>>& adj, int n){
        vector<bool> vis(n, false);
        stack<int> st;

        for (int i = 0; i<n; i++){
            if (!vis[i]){
                dfs(i, vis, adj, st);
            }
        }

        vector<int> ans;
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st){
        vis[u] = true;

        for (int v: adj[u]){
            if (!vis[v]){
                dfs(v, vis, adj, st);
            }
        }
        st.push(u);
    }
};
