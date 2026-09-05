class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for (int i = 0; i<=n; i++){
            ans[i] = count(i);
        }
        return ans;
    }

    int count(int n){
        int c = 0;
        while (n){
            n = n&(n-1);
            c++;
        }
        return c;
    }
};
