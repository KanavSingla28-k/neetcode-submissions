class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        solve(res, curr, 0, 0, n);

        return res;
    }

    void solve(vector<string>& res, string curr, int open, int close, int n){
        if (curr.size() == 2*n){
            res.push_back(curr);
            return;
        }

        if (open < n) solve(res, curr+'(', open+1, close, n);
        if (close < open) solve(res, curr+')', open, close+1, n);
    }
};
