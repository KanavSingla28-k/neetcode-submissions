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
        int sum = add(curr);
        if (target < sum || i == nums.size()) return;
        if (target == sum){
            if (!seen.count(curr)){
                res.push_back(curr);
                seen.insert(curr);
            }
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, target, res, curr, i+1);

        curr.pop_back();
        curr.push_back(nums[i]);
        solve(nums, target, res, curr, i);

        curr.pop_back();
        solve(nums, target, res, curr, i+1);
    }

    int add(vector<int>& curr){
        int sum = 0;
        for (int num: curr){
            sum += num;
        }
        return sum;
    }
};
