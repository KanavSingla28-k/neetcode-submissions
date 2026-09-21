class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i<n; i++){
            ans += pali(s, i, i);
            cout<<i<<" - "<<ans<<endl;
            ans += pali(s, i, i+1);
            cout<<i<<" - "<<ans<<endl;
        }
        return ans;
    }

    int pali(string s, int st, int end){
        int ans = 0;

        while (st>=0 && end<s.size() && s[st] == s[end]){
            ans++;
            st--;
            end++;
        }
        return ans;
    }
};
