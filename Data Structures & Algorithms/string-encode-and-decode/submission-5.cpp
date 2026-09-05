class Solution {
public:
    string separator = "#*#";
    int size = 3;

    string encode(vector<string>& strs) {
        string ans = "";

        for (string s: strs){
            ans += s;
            ans += separator;
        }

        return ans;
    }

    vector<string> decode(string s) {
        int st = 0;
        vector<string> res;

        while (st < s.size()){
            int end = s.find(separator, st);
            // if (st == end) {
            //     res.push_back(""); 
            //     st += end+size;
            //     continue;
            // }
            res.push_back(s.substr(st, end-st));

            st = end+size;
        }
        return res;
    }
};
