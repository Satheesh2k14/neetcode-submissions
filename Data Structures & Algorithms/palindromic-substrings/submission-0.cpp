class Solution {
public:
    void expandAroundCenter(string s, int left, int right, int& count) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {
        int start = 0;
        int maxLength = 0;
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            expandAroundCenter(s, i, i, count);
            expandAroundCenter(s, i, i + 1, count);
        }

        return count;
    }
};
