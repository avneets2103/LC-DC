class Solution {
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, int r, int c){
        if(dp[r][c]!=-1) return dp[r][c];
        if(c == grid[0].size()-1) return dp[r][c] = 0;
        int ans = 0;
        // up
        if(r-1 >= 0 && grid[r-1][c+1] > grid[r][c]){
            ans = max(1+solve(grid, r-1, c+1), ans);
        }
        // same
        if(grid[r][c+1] > grid[r][c]){
            ans = max(1+solve(grid, r, c+1), ans);
        }
        // down
        if(r+1 < grid.size()  && grid[r+1][c+1] > grid[r][c]){
            ans = max(1+solve(grid, r+1, c+1), ans);
        }
        return dp[r][c] = ans;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>> (m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i<m; i++){
            ans = max(ans, solve(grid, i, 0));
        }
        return ans;
    }
};