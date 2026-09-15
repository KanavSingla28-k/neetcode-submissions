class Solution {
public:
    int ans = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j] == 1 && !vis[i][j]){
                    int area = 0;
                    dfs(i, j, vis, grid, m, n, area);
                }
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid, int m, int n, int& area){
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0 || vis[i][j]) return;

        vis[i][j] = true;
        area++;

        dfs(i+1, j, vis, grid, m, n, area);
        dfs(i-1, j, vis, grid, m, n, area);
        dfs(i, j+1, vis, grid, m, n, area);
        dfs(i, j-1, vis, grid, m, n, area);

        ans = max(ans, area);
    }
};
