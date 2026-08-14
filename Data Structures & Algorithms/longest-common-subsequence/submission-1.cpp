class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //brute force
        // find smallest string
        //check if subsequence exists in big string for every subsequence not substring
        //eg: abczabc and abcyabc.. here answer is abcabc so 6

        // abc and abc exists.. abcz doesnt so we try abca, then abcab, then abcabc

        string minString = text1.size() < text2.size() ? text1 : text2;
        string maxString = text1.size() >= text2.size() ? text1 : text2;

        vector<int> previous(minString.size()+ 1, 0);
        vector<int> current(minString.size()+ 1, 0);

        for(int i = 1; i < maxString.size() + 1; i++) {
            for (int j = 1; j < minString.size() + 1; j++) {
                if (maxString[i - 1] == minString[j - 1]) {
                    current[j] = 1 + previous[j - 1];
                } else {
                    current[j] = max(previous[j], current[j - 1]);
                }
            }
            previous = current;
        }
        
        return current[minString.size()];
    }
};

/*

    -   a   b   c   y   a
-   0   0   0   0   0   0
a   0   1   1   1   1   1
b   0   1   2   2   2   2
c   0   1   2   3   3   3   
z   0   1   2   3   3   3
a   0   1   2   3   3   4


    -   a   b   c   y   a
-   0   0   0   0   0   0
-   0   1   1   1   1   1

-   0   1   2   2   2   2
c   0   1   2   3

*/
