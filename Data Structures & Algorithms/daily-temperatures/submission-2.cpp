class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();

        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for (int i = n-1; i>=0; i--){
            while (!st.empty() && t[i]>=st.top().first) st.pop();
            res[i] = st.empty() ? 0: st.top().second-i;

            st.push({t[i], i});
        }

        return res;
    }
};
