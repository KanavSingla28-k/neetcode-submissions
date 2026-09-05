class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
        int i = 0, j = n-1;

        while (i<j){
            int val = nums[i]+nums[j];
            if (val == t) return {i+1, j+1};
            else if (val<t) i++;
            else j--;
        }

        return {};
    }
};
