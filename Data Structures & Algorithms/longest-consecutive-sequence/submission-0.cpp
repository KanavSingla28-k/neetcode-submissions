class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        int curr = -1;
        int streak = 0;
        int ans = 0;

        for (int num: nums){
            if (!s.count(num-1)){
                curr = num;
                streak = 1;
                while (s.count(curr+1)){
                    curr++;
                    streak++;
                }
                ans = max(ans, streak);
            }
        }
        return ans;
    }
};
