class Solution {
public:
    set<vector<int>> seen;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(nums, target, res, curr, 0);

        return res;
    }

    void solve(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& curr, int i){
        if (target < 0 || i == nums.size()) return;
        if (target == 0){
            if (!seen.count(curr)){
                res.push_back(curr);
                seen.insert(curr);
            }
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, target-nums[i], res, curr, i+1);

        curr.pop_back();
        curr.push_back(nums[i]);
        solve(nums, target-nums[i], res, curr, i);

        curr.pop_back();
        solve(nums, target, res, curr, i+1);
    }
};
