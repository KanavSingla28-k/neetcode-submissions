class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int ans = 0;
        while (!q.empty() && fresh>0){
            int size = q.size();
            for (int k = 0; k<size; k++){
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir: direction){
                    int nr = r+dir[0], nc = c+dir[1];

                    if (nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if (fresh>0) return -1;
        return ans;
    }
};
