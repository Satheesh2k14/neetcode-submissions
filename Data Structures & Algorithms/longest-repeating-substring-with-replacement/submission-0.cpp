class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> frequency;
        //initialize all upperCase to 0
        for (char c = 'A'; c <= 'Z'; c++){
            frequency[c] = 0;
        }
        int left = 0, right = 0, answer = 0, maxFrequency = 0;

        while(right < s.length()) {
            frequency[s[right]] += 1;

            maxFrequency = max(maxFrequency, frequency[s[right]]);

            if ((right - left + 1) - maxFrequency > k) {
                frequency[s[left]] -= 1;
                left++;
            }

            answer = max(answer, right - left + 1);
            right++;
        }

        return answer; 
    }
};
