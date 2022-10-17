class Solution {
public:
    long long int mod = 1000000007;
    int f(int i, int j, int sum, int k, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        if(i == 0 and j == 0){
            if((grid[i][j] + sum)%k == 0) return 1;
            return 0;   
        }
        if(dp[i][j][sum%k]!=-1) return dp[i][j][sum%k];
        int up = 0, left = 0;
        if(i > 0){
            up = f(i-1, j, sum + grid[i][j], k, grid, dp);
        }
        if(j > 0){
            left = f(i, j-1, sum + grid[i][j], k, grid, dp);
        }
        return dp[i][j][sum%k] = (up%mod + left%mod) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(51, -1)));
        int ans = f(n-1, m-1, 0, k, grid, dp);
        return ans;
    }
};