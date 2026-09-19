class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> pq;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            int d = x * x + y * y;

            if (pq.size() < k) {
                pq.push({d, point});
            }
            else if (pq.top().first > d) {
                pq.pop();
                pq.push({d, point});
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};