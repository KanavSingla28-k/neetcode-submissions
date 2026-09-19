class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        solve(nums, res, curr, 0, t);
        return res;
    }

    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int i, int t){
        if (t == 0){
            res.push_back(curr);
            return;
        }

        if (t<0 || i == nums.size()) return;

        for (int j = i; j<nums.size(); j++){
            if (j>i && nums[j] == nums[j-1]) continue;
            if (nums[j]>t) break;
            curr.push_back(nums[j]);
            solve(nums, res, curr, j+1, t-nums[j]);

            curr.pop_back();
        }
        
    }
};