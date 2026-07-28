class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

       // 0 1 0 2 3
       // 100 150 0 200 250
        int elementCount = nums.size();
        vector<int> lis(elementCount, 1);
        //lis[nums[elementCount - 1]] = 1;
        int currentIndex = elementCount - 2; //5 elements, then index 3
        int answer = 1;
        while (currentIndex > -1) {
            int toExtendIndex = currentIndex + 1;
            while (toExtendIndex < elementCount) {
                if (nums[currentIndex] < nums[toExtendIndex]) {
                    lis[currentIndex] = max(lis[currentIndex], 1 + lis[toExtendIndex]);
                }
                toExtendIndex += 1;
            }
            answer = max(answer, lis[currentIndex]);
            currentIndex -= 1;
        }

        return answer;
    }
};

/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       // 9
       // 1
       // 1 4
       // 1 2
       // 1 2 3
       // 1 2 3 7

       int answer = 1;
       stack<int> increasing;
       //increasing.push(nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            if (increasing.empty()) {
                increasing.push(current);
            } else {
                if(increasing.top() < current) {
                    increasing.push(current);
                    answer = max(answer, increasing.size());
                } else {
                    while(increasing.top() >= current) {
                        increasing.pop();
                    }
                    increasing.push(current);
                    answer = max(answer, increasing.size());
                }
            }
        }

        return answer;
    }
};

*/