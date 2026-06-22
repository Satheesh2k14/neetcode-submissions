class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //can remove non-overlapping intervals from consideration
        //idea - biggest window remove will be minimum
        //idea - connecting window remove will be minimum

        //3 use-cases?
        //1 - full consumation example [[1,2],[2,4],[1,4]]
        //2 - intersection [[1,3],[2,4],[3,5]] - here remove 2,4 
        //
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; });

        int answer = 0, prevEnd = INT_MIN;
        for (auto interval : intervals) {
            if (interval[0] < prevEnd) {
                answer += 1;
            } else {
                prevEnd = interval[1];
            }
        }

        return answer;
    }
};
