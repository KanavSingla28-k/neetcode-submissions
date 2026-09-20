class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<pair<int, int>> q;

        q.push({0, -1});
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            auto [curr, parent] = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (neighbor == parent) continue;

                if (visited[neighbor]) return false;

                visited[neighbor] = true;
                q.push({neighbor, curr});
                count++;
            }
        }

        return count == n;
    }
};
