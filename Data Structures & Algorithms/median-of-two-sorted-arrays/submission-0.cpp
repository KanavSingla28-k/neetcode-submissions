class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int half = (total + 1) / 2;

        int l = 0;
        int r = m;

        while (l <= r) {

            int cut1 = l + (r - l) / 2;
            int cut2 = half - cut1;

            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                if (total % 2 == 1) {
                    return max(left1, left2);
                }

                return (max(left1, left2) + 
                        min(right1, right2)) / 2.0;
            }

            // Too many elements taken from nums1
            else if (left1 > right2) {
                r = cut1 - 1;
            }

            // Too few elements taken from nums1
            else {
                l = cut1 + 1;
            }
        }

        return 0.0;
    }
};