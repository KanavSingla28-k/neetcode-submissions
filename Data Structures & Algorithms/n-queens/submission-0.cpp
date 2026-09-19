class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        nqueen(board, res, 0, n);
        return res;
    }

    void nqueen(vector<string>& board, vector<vector<string>>& res, int row, int n){
        if (row == n){
            res.push_back(board);
            return;
        }

        for (int i = 0; i<n; i++){
            if (isSafe(board, row, i, n)){
                board[row][i] = 'Q';
                nqueen(board, res, row+1, n);
                board[row][i] = '.';
            }
        }
    }

    bool isSafe(vector<string>& board, int row, int col, int n){
        for (int i = 0; i<n; i++){
            if (board[row][i] == 'Q') return false;
        }

        for (int i = 0; i<n; i++){
            if (board[i][col] == 'Q') return false;
        }

        int r = row, c = col;

        while(r>=0 && c>=0){
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        r = row, c = col;

        while(r>=0 && c>=0){
            if (board[r][c] == 'Q') return false;
            r--; c++;
        }

        return true;
    }
};