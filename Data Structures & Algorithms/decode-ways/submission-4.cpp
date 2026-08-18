class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int sLength = s.size();
        vector<int> dp(sLength + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        //check valid answer exists cannot start with 0 before other digit
        //30 is also not valid, 0 shoudl preced with 1 or 2, above 26 is not valid

        for (int i = 2; i <= sLength; i++) {
            if(s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit < 27 && twoDigit > 9) {
                dp[i] +=  dp[i - 2];
            }
        }


        return dp[sLength];
    }
};

/*

        for (int i = 2; i < sLength; i++) {
            if(s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit < 27 && twoDigit > 9) {
                dp[i] +=  dp[i - 2];
            }
        }


        return dp[sLength];
    }
*/
/*
3 3 3

11
1 ans 1
11 ans 1+1

1111

1 1 1
1 11
11 1

1 1 1 1
1 1 11
1 11 1
11 1 1
11 11

i   0   1   2   3   4
va  1   1   1   1   0
ans 3+2   2+1   2   1   0
*/