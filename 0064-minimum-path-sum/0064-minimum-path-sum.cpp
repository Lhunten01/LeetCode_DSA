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
        // return minSum(n-1,m-1,grid,dp);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {  
                if(i==0&&j==0)
               {
                 dp[i][j]=grid[0][0];
                 continue;
               } 
                 int top=1e8,left=1e8;
                if(i-1>=0) top=grid[i][j]+dp[i-1][j];
                if(j-1>=0) left=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(top,left);
            }
        }
        return dp[n-1][m-1];
    }
};