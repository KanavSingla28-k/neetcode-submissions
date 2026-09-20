class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if (pa == pb){
            return false;
        }
        
        if (rank[pa]<rank[pb]) swap(pa, pb);

        parent[pb] = pa;

        if (rank[pa] == rank[pb]) rank[pa]++;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 1; i<=n; i++){
            parent[i] = i;
        }

        for (auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)){
                return {u, v};
            }
        }
        return {};

    }
};
