class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i<n; ++i){
            int compi = target-nums[i];
            for (int j = i+1; j<n; ++j){
                // if (i == j) continue;
                if (nums[j] == compi){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
                
            }
        }
        return res;
    }
};
