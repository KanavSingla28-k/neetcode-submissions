class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int> pref(n, -1);
        int maxh = -1;
        for (int i = 0; i<n; i++){
            if (h[i]<maxh) pref[i] = maxh;
            maxh = max(maxh, h[i]);
        }

        vector<int> suff(n, -1);
        maxh = -1;
        for (int i = n-1; i>=0; i--){
            if (h[i]<maxh) suff[i] = maxh;
            maxh = max(maxh, h[i]);
        }

        int ans = 0;
        for (int i = 0; i<n; i++){
            if (pref[i] == -1 || suff[i] == -1) continue;
            ans += min(pref[i], suff[i]) - h[i];
        }
        return ans;
    }
};
