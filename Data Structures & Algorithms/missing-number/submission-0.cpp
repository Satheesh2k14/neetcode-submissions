class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xore = 0;
        for (int i = 1; i <= nums.size(); i++) {
            xore ^= i;
        }
        for (int i = 0; i < nums.size(); i++) {
            xore ^= nums[i];
        }

        return xore;
    }
};
