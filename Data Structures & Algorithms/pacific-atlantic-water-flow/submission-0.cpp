class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();

        // pacific islands
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));

        //initialize with true
        for (int j = 0; j < cols; j++) {
            pacific[0][j] = 1;
            dfs(0, j, heights, pacific);
        }
        for (int i = 1; i < rows; i++) {
            pacific[i][0] = 1;
            dfs(i, 0, heights, pacific);
        }
        

        // atlantic islands
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        //initialize with true
        for (int j = 0; j < cols; j++) {
            atlantic[rows - 1][j] = 1;
            dfs(rows - 1, j, heights, atlantic);
        }
        for (int i = rows - 1; i >= 0; i--) {
            atlantic[i][cols - 1] = 1;
            dfs(i, cols - 1, heights, atlantic);
        }
        // intersection at the end and return result
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        //right
        if (j < heights[0].size() - 1 && ocean[i][j+1] == 0 && heights[i][j] <= heights[i][j+1]) {
            ocean[i][j + 1] = 1;
            dfs(i, j + 1, heights, ocean);
        }
        // left
        if (j > 0 && ocean[i][j-1] == 0 && heights[i][j] <= heights[i][j-1]) {
            ocean[i][j - 1] = 1;
            dfs(i, j - 1, heights, ocean);
        }
        // up
        if (i > 0 && ocean[i-1][j] == 0 && heights[i][j] <= heights[i-1][j]) {
            ocean[i - 1][j] = 1;
            dfs(i - 1, j, heights, ocean);
        }
        // down
        if (i < heights.size() -1 && ocean[i+1][j] == 0 && heights[i][j] <= heights[i+1][j]) {
            ocean[i + 1][j] = 1;
            dfs(i + 1, j, heights, ocean);
        }
    }
};
