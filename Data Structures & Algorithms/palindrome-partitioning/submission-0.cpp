class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        solve(s, curr, res);
        return res;
    }

    void solve(string s, vector<string> &curr, vector<vector<string>> &res){
        if (s == ""){
            res.push_back(curr);
            return;
        }

        for (int i = 0; i<s.size(); i++){
            string p = s.substr(0, i+1);
            if (isp(p)){
                curr.push_back(p);
                solve(s.substr(i+1), curr, res);
                curr.pop_back();
            }
        }
    }

    bool isp(string p){
        for (int i = 0; i<p.size()/2; i++){
            if (p[i] != p[p.size()-i-1]) return false;
        }
        return true;
    }
};
