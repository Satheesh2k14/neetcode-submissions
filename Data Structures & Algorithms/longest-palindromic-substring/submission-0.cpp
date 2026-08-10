class Solution {
public:

    int expandAroundCenter(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 0;

        for(int i = 0; i < s.length(); i++) {
            int length1 = expandAroundCenter(s, i, i);
            int length2 = expandAroundCenter(s, i, i + 1);

            int currentMax = max(length1, length2);

            if (currentMax > maxLength) {
                maxLength = currentMax;
                // Calculate the new start position based on the center 'i'
                start = i - (currentMax - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
        
    }
};
