class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int n = mat[0].size();

        int i = 0, j = n-1;

        while (i>=0 && j>=0 && i<m && j<n){
            if (mat[i][j] == t) return true;
            else if (mat[i][j] < t) i++;
            else j--;
        }

        return false;
    }
};
