class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m != n) return false;
        int arr[26] = {0};

        for (int i = 0; i<n; i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }

        for (int num: arr){
            if (num != 0) return false;
        }
        return true;
    }
};
