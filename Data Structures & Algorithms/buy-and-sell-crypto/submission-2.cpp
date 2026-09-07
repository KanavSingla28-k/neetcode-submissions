class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int rmax = -1;
        vector<int> ans(n);

        for (int i = n-1; i>=0; i--){
            if (prices[i]>=rmax){
                rmax = prices[i];
                ans[i] = -1;
            }
            else{
                ans[i] = rmax-prices[i];
            }
        }

        int a = *max_element(ans.begin(), ans.end());

        return (a == -1) ? 0: a;
    }
};
