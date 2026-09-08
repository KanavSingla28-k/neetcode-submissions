class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n-1;

        while (l<=r){
            int mid = l+(r-l)/2;

            if (nums[mid] == target) return mid;

            else if (nums[mid]<target){
                // mid to right sorted and present
                if (nums[mid]<=nums[r] && nums[r]>target) l = mid+1;
                // mid to right sorted but not present
                else if (nums[mid]<=nums[r] && nums[r]<target) r = mid-1;

                // mid to right unsorted
                else l = mid+1;
            }

            else{
                // left to mid sorted and present
                if (nums[l]<=nums[mid] && nums[l]<target) r = mid-1;
                // left to mid sorted but not present
                else if (nums[l]<=nums[mid] && nums[l]>target) l = mid+1;

                // left to mid unsorted
                else r = mid-1;
            }
        }
        return -1;
    }
};
