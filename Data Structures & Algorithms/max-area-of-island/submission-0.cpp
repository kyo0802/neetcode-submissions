class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    int dfs(int i, int j, vector<vector<int>>& grid) {

        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;

        int area = 1;

        area += dfs(i-1,j,grid);
        area += dfs(i+1,j,grid);
        area += dfs(i,j-1,grid);
        area += dfs(i,j+1,grid);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1 && !visited[i][j]) {

                    int area = dfs(i, j, grid);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
