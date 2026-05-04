class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, numOfZeroes = 0, productWithoutZero = 1;
        for(int num : nums) {
            product *= num;
            if (num != 0) {
                productWithoutZero *= num;
            }
            if (num == 0) {
                numOfZeroes += 1;
            }
            cout << product << endl;
        }
        cout << product << " " << productWithoutZero << endl;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            if (product == 0 && nums[i] == 0 && numOfZeroes == 1) {
                output.push_back(productWithoutZero);
            } else if (product == 0) {
                output.push_back(product);
            } else {
                int temp = product / nums[i];
                output.push_back(temp);
            }

        }

        return output;
    }
};
