class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int winlen = s1.size();
        int n = s2.size();

        vector<int> arr(26, 0);
        
        for (char c: s1) arr[c-'a']++;

        int l = 0;

        for (int r = 0; r<n; r++){
            if (r<winlen-1){
                arr[s2[r]-'a']--;
                continue;
            }

            arr[s2[r]-'a']--;
            bool nxt = false;
            for (int x: arr){
                if (x != 0) nxt = true;
            }

            if (!nxt) return true;

            arr[s2[l]-'a']++;
            l++;        
        }
        return false;
    }
};
