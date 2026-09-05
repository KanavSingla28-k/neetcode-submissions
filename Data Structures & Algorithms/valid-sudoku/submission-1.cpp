class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') { 
                    if (rows[i].count(num) > 0) {
                        return false; 
                    }
                    rows[i].insert(num);

                    if (cols[j].count(num) > 0) {
                        return false; 
                    }
                    cols[j].insert(num);

                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (boxes[boxIndex].count(num) > 0) {
                        return false;
                    }
                    boxes[boxIndex].insert(num);
                }
            }
        }
        return true; 
    }
};