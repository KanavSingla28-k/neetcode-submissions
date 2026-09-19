class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(nums, curr, res, 0);

        return res;
    }

    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& res, int i){
        if (i == nums.size()){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, curr, res, i+1);

        curr.pop_back();
        solve(nums, curr, res, i+1);
    }
};
