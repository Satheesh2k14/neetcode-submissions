class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // reverse
        int stringLen = s.size();
        vector<int> dp(stringLen + 1, 0);
        dp[stringLen] = 1;

        for (int i = stringLen - 1; i >= 0; i--){
            for(string w : wordDict) {
                if ((i + w.size() <= stringLen) && (s.substr(i, w.size()) == w)) {
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) 
                    break;
            }
        }
        return dp[0] == 1;
    }

};

/*

c a t s i n c a r s
0 0 0 0 0 0 1 0 1 0

*/