class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> answer;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            //merge
            if (current[1] >= intervals[i][0]) {
                current[1] = max(intervals[i][1], current[1]);
            } else {
                answer.push_back(current);
                current = intervals[i];
            }
        }
        answer.push_back(current);

        return answer;
    }
};
