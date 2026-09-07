class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int maxi = INT_MIN;

        // Find maximum of first window
        for (int i = 0; i < k; i++) {
            maxi = max(maxi, nums[i]);
        }

        ans.push_back(maxi);

        // Slide the window
        for (int i = k; i < nums.size(); i++) {

            // If new element is bigger, update maximum
            if (nums[i] > maxi)
                maxi = nums[i];

            // If old maximum is leaving, find new maximum
            else if (nums[i - k] == maxi) {
                maxi = nums[i - k + 1];

                for (int j = i - k + 1; j <= i; j++) {
                    maxi = max(maxi, nums[j]);
                }
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};