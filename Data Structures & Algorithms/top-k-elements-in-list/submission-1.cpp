class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num: nums){
            mp[num]++;
        }

        vector<pair<int, int>> vec;

        for (auto& p: mp){
            vec.push_back({p.second, p.first});
        }

        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        vector<int> res;

        for (int i = 0; i<k; i++){
            res.push_back(vec[i].second);
        }
        return res;
    }
};
