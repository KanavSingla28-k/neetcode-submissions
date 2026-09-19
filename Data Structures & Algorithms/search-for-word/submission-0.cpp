class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (solve(board, word, 0, i, j, n, m))
                    return true;
            }
        }

        return false;
    }

    bool solve(vector<vector<char>>& board, string& word, int idx, int i, int j, int n, int m) {

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (board[i][j] != word[idx])
            return false;

        if (idx == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            solve(board, word, idx + 1, i + 1, j, n, m) ||
            solve(board, word, idx + 1, i - 1, j, n, m) ||
            solve(board, word, idx + 1, i, j + 1, n, m) ||
            solve(board, word, idx + 1, i, j - 1, n, m);

        board[i][j] = temp;

        return found;
    }
};