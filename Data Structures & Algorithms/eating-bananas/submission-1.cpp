class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int k = -1;

        while (l<=r){
            int mid = l + (r-l)/2;

            if (pos(mid, piles, h)){
                k = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return k;
    }

    bool pos(int k, vector<int>& piles, int h){
        int hrs = 0;

        for (int pile: piles){
            hrs += (pile+k-1)/k;
        }

        if (hrs>h) return false;
        return true;
    }
};
