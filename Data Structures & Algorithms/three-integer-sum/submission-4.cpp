class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int k = 0; k<n-2; k++){
            if (k>0 && nums[k] == nums[k-1]) continue;   
            int t = 0-nums[k];         
            
            int i = k+1, j = n-1;
            while (i<j){
                int val = nums[i]+nums[j];
                if (val == t) res.push_back({nums[k], nums[i++], nums[j--]});
                else if (val<t) i++;
                else j--;
                while (i<j && i>k+1 && nums[i] == nums[i-1]) i++;
                while (i<j && j<n-1 && nums[j] == nums[j+1]) j--;
            }
        }

        return res;
    }
};
