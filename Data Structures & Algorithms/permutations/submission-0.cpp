class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        solve(nums, res, n, 0);
        return res;
    }

    void solve(vector<int>& nums, vector<vector<int>>& res, int n, int idx){
        if (idx == n){
            res.push_back(nums);
            return;
        }

        for (int i = idx; i<n; i++){
            swap(nums[i], nums[idx]);
            solve(nums, res, n, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};
