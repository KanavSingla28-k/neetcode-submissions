class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int> left(n, -1), right(n, n);

        stack<pair<int, int>> st;
        for (int i = 0; i<n; i++){
            while (!st.empty() && h[i]<=st.top().first) st.pop();

            left[i] = st.empty() ? -1: st.top().second;
            st.push({h[i], i});
        }

        stack<pair<int, int>> st1;
        for (int i = n-1; i>=0; i--){
            while (!st1.empty()  && h[i]<=st1.top().first) st1.pop();

            right[i] = st1.empty() ? n: st1.top().second;
            st1.push({h[i], i});
        }

        int maxarea = 0;

        for (int i = 0; i<n; i++){
            int curr = h[i]*(right[i]-left[i]-1);

            maxarea = max(curr, maxarea);
        }

        return maxarea;
    }
};
