class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> output(n, 1);

        for (int i = 0; i<n; ++i){
            for (int j = 0; j<i; ++j){
                prefix[i] *= nums[j];
            }
        }

        for (int i = 0; i<n; ++i){
            for (int j = n-1; j>i; --j){
                suffix[i] *= nums[j];
            }
        }

        for (int i = 0; i<n; ++i){
            output[i] = prefix[i]*suffix[i];
        }

        return output;
        
    }
};
