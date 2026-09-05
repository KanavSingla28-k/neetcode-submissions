class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res(k, 0);

        for (int num:nums){
            freq[num]++;
        }

        vector<pair<int, int>> mypair(freq.begin(), freq.end());

        sort(mypair.begin(), mypair.end(), [](const auto &a, const auto &b){
            return a.second>b.second;
        });

        for (int i = 0; i<k; ++i){
            res[i] = mypair[i].first;
        }
        return res;
    }
};
