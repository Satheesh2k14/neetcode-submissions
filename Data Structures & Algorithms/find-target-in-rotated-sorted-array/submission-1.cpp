class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        // modified binary search

        int left = 0, right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left)/2;

            if (nums[mid] == target) return mid;

            //check if left is sorted
            if (nums[left] <= nums[mid]) {
                //check if element inside sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            } else {
                //right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }

            }
        }

        return -1;
    }
};
