class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();

        unordered_map<char, int> seen;
        for (int i = 0; i<m; ++i){
            seen[s[i]]++;
        }

        for (int i = 0; i<n; ++i){
            if (seen.count(t[i])){
                if (seen[t[i]] == 1) seen.erase(t[i]);
                else seen[t[i]]--;
            }
            else return false;
        }
        return (seen.size() == 0);
    }
};
