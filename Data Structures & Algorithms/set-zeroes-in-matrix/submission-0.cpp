class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        string row = "", column ="";

        int numRows = matrix.size(), numColumns = matrix[0].size();

        for (int i = 0; i < numRows; i++) {
            row += "1";
        }
        for (int i = 0; i < numColumns; i++) {
            column += "1";
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = '0';
                    column[j] = '0';
                }
            }
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                if (row[i] == '0' || column[j] == '0') {
                    matrix[i][j] = 0;
                }
            }
        }



    }
};
