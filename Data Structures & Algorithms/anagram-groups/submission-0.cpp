class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myhash;
        vector<vector<string>> res;

        for (const auto& s: strs){
            string sortedver = s;
            sort(sortedver.begin(), sortedver.end());
            myhash[sortedver].push_back(s);
        }

        for (auto& e: myhash){
            res.push_back(e.second);
        }
        return res;
    }
};
