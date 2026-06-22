/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> startEnd;
        for (auto interval: intervals) {
            startEnd.push_back(make_pair(interval.start, 1));
            startEnd.push_back(make_pair(interval.end, 0));
        }

        sort(startEnd.begin(), startEnd.end());

        int answer = 0, activeCount = 0;
        for (auto item: startEnd) {
            if (item.second == 1) activeCount++;
            else activeCount--;
            answer = max(answer, activeCount);
        }

        return answer;
    }
};
