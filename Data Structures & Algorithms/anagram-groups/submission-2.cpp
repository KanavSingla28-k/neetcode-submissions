class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for (string s: strs){
            string code = encode(s);
            mp[code].push_back(s);
        }

        for (auto& p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }

    string encode(string s){
        int arr[26] = {0};

        for (char c: s){
            arr[c-'a']++;
        }

        string code = "";

        for (int x: arr){
            code += (to_string(x));
            code += "#";
        }
        return code;
    }
};
