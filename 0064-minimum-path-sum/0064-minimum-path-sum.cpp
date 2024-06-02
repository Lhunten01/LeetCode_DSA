class Solution {
public:
    int minSum(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {  if(i<0||j<0)
        return 1e8;
        if(i==0&&j==0)
        return grid[0][0];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int top=grid[i][j]+minSum(i-1,j,grid,dp);
        int left=grid[i][j]+minSum(i,j-1,grid,dp);
        return dp[i][j]=min(top,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
       
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
        return minSum(n-1,m-1,grid,dp);
    }
};