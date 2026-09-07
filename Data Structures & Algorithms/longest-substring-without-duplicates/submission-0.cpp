class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> seen;

        int left = 0;
        int ans = 0;

        for (int right = 0; right<n; right++){
            while(seen.count(s[right])) {
                seen.erase(s[left++]);
            }

            seen.insert(s[right]);
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
