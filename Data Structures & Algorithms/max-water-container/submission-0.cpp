class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int area = 0;

        int i = 0, j = n-1;
        while (i<j){
            if (h[i]<h[j]){
                area = max(area, h[i]*(j-i));
                i++;
            }
            else {
                area = max(area, h[j]*(j-i));
                j--;
            }
            
        }
        return area;
    }
};
