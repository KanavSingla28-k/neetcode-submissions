class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while (l<r){
            if (h[l]<h[r]){
                if (h[l]>lmax) lmax = h[l];
                else ans += lmax-h[l];
                l++;
            }
            else{
                if (h[r]>rmax) rmax = h[r];
                else ans += rmax-h[r];
                r--;
            }
        }
        return ans;
    }
};
