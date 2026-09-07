class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minum = INT_MAX;
        for (int price: prices){
            profit = max(profit, price-minum);
            minum = min(price, minum);
        }
        return profit;
    }
};
