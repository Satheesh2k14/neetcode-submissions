class Solution {
public:
    vector<int> countBits(int n) {
        // 0 0
        // 1 01
        // 2 10
        // 3 11
        // 4 100
        // 5 101
        // 6 110
        // 7 111
        // 8 1000
        // 9 1001
        //10 1010
        //11 1011
        //12 1100
        //13 1101
        //14 1110
        //15 1111
        //16 10000
        // shift and & with 1 to find 1 and then increment
        // n * log n
        vector<int> dp(n + 1, 0);
        int offset = 1, i = 1;
        while (i <= n) {
            if(i == offset * 2) offset = i;

            dp[i] = 1 + dp[i - offset];
            i++;
        }
        return dp;
    }
};
