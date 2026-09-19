class Solution {
public:
    set<vector<int>> seen;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        solve(nums, res, curr, 0);

        return res;
    }

    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int i){
        if (i == nums.size()){
            if (!seen.count(curr)){
                res.push_back(curr);
                seen.insert(curr);
            }   
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, res, curr, i+1);

        curr.pop_back();
        solve(nums, res, curr, i+1);
    }
};
