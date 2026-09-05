class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;

        int real = 0;
        for (int num: nums){
            real += num;
        }

        return sum-real;
    }
};
