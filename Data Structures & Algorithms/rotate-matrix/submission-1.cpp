class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //handle 0 case do nothing
        // n/2 rotations
        int n = matrix[0].size();
        int rotations = n / 2;

        if (rotations == 0) return;

        for(int i = 0; i < rotations; i++) {
            for (int j = i; j < n - 1 - i; j++) {

                // 1st element in rotation row
                int current = matrix[i][j];
                int next = matrix[j][n - 1 - i];

                matrix[j][n - 1 - i] = current;
                
                current = next;
                next = matrix[n - 1 - i][n - 1 - j];

                matrix[n - 1 - i][n - 1 - j] = current;

                current = next;
                next = matrix[n - 1 - j][i];

                matrix[n - 1 - j][i] = current;
                
                current = next;
                matrix[i][j] = current;
            }

            //print temp matrix
            for(int i = 0; i < n; i++) {
                for (int j = 0; j < n ; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << "boom baa diga" << endl;
        }

    }
};
