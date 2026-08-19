class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       //direction right, down, left, right
       //bounds in each direction
        int leftM = 0, rightM = matrix[0].size() - 1, topM = 0, bottomM = matrix.size() - 1;

        vector<int> answer;
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0, i = 0, j = 0;
         cout << "left " << leftM << " right " << rightM << " top " << topM << " bottom " << bottomM <<endl;
        while (leftM <= rightM && topM <= bottomM) {
            cout << " i " << i << " j " << j << endl;
            while (i >= topM && i <= bottomM && j >= leftM && j <= rightM) {
                answer.push_back(matrix[i][j]);
                i += direction[directionIndex].first;
                j += direction[directionIndex].second ; 
            }
            directionIndex = (directionIndex + 1) % 4;
            cout << "directionIndex " << directionIndex << endl;
            //first topM += 1, then rightM -= 1, then bottomM -= 1, then leftM += 1
            switch (directionIndex) {
                case 0: {
                    leftM += 1;
                    i = topM;
                    j = leftM;
                    break;
                };
                case 1: {
                    topM += 1;
                    i = topM;
                    j = rightM;
                    break;
                };
                case 2: {
                    rightM -= 1;
                    i = bottomM;
                    j = rightM;
                    break;
                };
                case 3: {
                    bottomM -= 1;
                    i = bottomM;
                    j = leftM;
                    break;
                };
                default: break;
            }
            //cout << "rowChange " << rowChange << " colChange " << colChange << endl;
            cout << "left " << leftM << " right " << rightM << " top " << topM << " bottom " << bottomM <<endl;
            //change i and j
            //

        }

        return answer; 
    }
};
