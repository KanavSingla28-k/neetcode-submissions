class TN{
public:
    TN* children[26];
    bool isEnd;
    TN(){
        for (int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        isEnd = false;
    }

    void addword(string word){
        TN* curr = this;

        for (char c: word){
            int i = c-'a';

            if (curr->children[i] == nullptr){
                curr->children[i] = new TN();
            }
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }
};

class Solution {
public:
    set<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TN* root = new TN();
        for (string word: words){
            root->addword(word);
        }

        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i<row; i++){
            for (int j = 0; j<col; j++){
                dfs(board, vis, i, j, root, "");
            }
        }

        return vector<string>(res.begin(), res.end());

    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j, TN* node, string word){
        int row = board.size(), col = board[0].size();

        if (i<0 || j<0 || i>=row || j>=col || vis[i][j] || !node->children[board[i][j]-'a']) return;

        vis[i][j] = true;
        node = node->children[board[i][j]-'a'];
        word += board[i][j];
        if (node->isEnd){
            res.insert(word);
        }

        dfs(board, vis, i+1, j, node, word);
        dfs(board, vis, i-1, j, node, word);
        dfs(board, vis, i, j+1, node, word);
        dfs(board, vis, i, j-1, node, word);

        vis[i][j] = false;
    }
};
