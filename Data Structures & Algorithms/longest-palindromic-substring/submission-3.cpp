class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        int st = 0, end = 0;


        for (int i = 0; i<n; i++){
            int odd = pali(s, i, i);
            int even = pali(s, i, i+1);

            int len = max(odd, even);
            if (len>end-st){
                st = i-(len-1)/2;
                end = i+len/2;
            }
        }

        return s.substr(st, end-st+1);
    }

    int pali(string s, int st, int end){
        while (st>=0 && end<s.size() && s[st] == s[end]){
            st--;
            end++;
        }

        return end-st-1;
    }
};
