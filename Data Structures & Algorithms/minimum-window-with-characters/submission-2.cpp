class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n < m) return "";

        unordered_map<char, int> window;
        unordered_map<char, int> target;

        for (char c: t) target[c]++;

        int have = 0;
        int need = target.size();

        int min_len = INT_MAX;
        int start = 0;

        int l = 0;

        for (int r = 0; r<n; r++){
            char c = s[r];
            window[c]++;

            if (target.count(c) && target[c] == window[c]) have++;

            while (have == need){
                if (r-l+1 < min_len){
                    min_len = r-l+1;
                    start = l;
                }

                char remove = s[l];
                window[remove]--;

                if (target.count(remove) && window[remove] < target[remove]) have--;
                l++;
            }
        }

        return (min_len == INT_MAX) ? "": s.substr(start, min_len);


    }
};
