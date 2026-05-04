class Solution {
public:
    int findMin(vector<int> &nums) {
        //binary search
        //~find no. of rotations
        // nums[l] < nums[r] then sorted, so return nums[l]

        int l = 0, r = nums.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
