class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequencies
        for (int num : nums) {
            mp[num]++;
        }

        // bucket[f] = numbers that occur f times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& p : mp) {
            int num = p.first;
            int freq = p.second;

            bucket[freq].push_back(num);
        }

        vector<int> res;

        // Start from highest frequency
        for (int freq = nums.size(); freq >= 1; freq--) {

            for (int num : bucket[freq]) {
                res.push_back(num);

                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};