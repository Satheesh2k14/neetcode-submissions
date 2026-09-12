class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        //Build hashmap of frequency
        int tSize = t.length(), sSize = s.length();
        vector<int> tFreq(58, 0), currentFreq(58, 0);
        for(int i = 0; i < tSize; i++) {
            //cout << t[i] << " ";
            tFreq[t[i] - 'A'] += 1;
        }
        
        //sliding window
        int left = 0, right = 0, counter = 0;
        int ansStart = 0, length = INT_MAX;

        while (right < sSize) {
            //process right element
            int currentIndex = s[right] - 'A';
            currentFreq[currentIndex] += 1;

            if (currentFreq[currentIndex] <= tFreq[currentIndex]) {
                counter++;
            }

            //shrink and check valid answer
            while (counter == tSize) {
                int currWinLength = right - left + 1;

                if (currWinLength < length) {
                    length = currWinLength;
                    ansStart = left;
                }

                int leftIndex = s[left] - 'A';
                if(currentFreq[leftIndex] == tFreq[leftIndex]) {
                    counter--;
                }

                currentFreq[leftIndex]--;
                left++;
            }
            

            right++;
        }

        return (length == INT_MAX) ? "" : s.substr(ansStart, length);
    }
};
