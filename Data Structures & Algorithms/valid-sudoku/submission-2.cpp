class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check for rows
        for (int row = 0; row<9; row++){
            set<char> seen1;
            for (int col = 0; col<9; col++){
                char c = board[row][col];
                if (!valid(c, seen1)) return false;
            }
        }

        // check for cols
        for (int col = 0; col<9; col++){
            set<char> seen2;
            for (int row = 0; row<9; row++){
                char c = board[row][col];
                if (!valid(c, seen2)) return false;
            }
        }

        // check for grid
        for (int i = 0; i<9; i+=3){
            for (int j = 0; j<9; j+=3){
                set<char> seen3;
                for (int row = i; row<i+3; row++){
                    for (int col = j; col<j+3; col++){
                        char c = board[row][col];
                        if (!valid(c, seen3)) return false;
                    }
                }
            }
        }

        return true;
    }

    bool valid(char c, set<char>& seen){
        if (c == '.') return true;

        if (seen.count(c)) return false;

        seen.insert(c);
        return true;
    }
};
