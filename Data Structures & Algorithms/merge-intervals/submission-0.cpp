class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        vector<int> m = intervals[0];

        for (int i = 1; i<intervals.size(); i++){
            if (intervals[i][0] <= m[1]){
                m[0] = min(m[0], intervals[i][0]);
                m[1] = max(m[1], intervals[i][1]);
                continue;
            }

            res.push_back(m);
            m = intervals[i];
        }

        res.push_back(m);
        return res;
    }
};
