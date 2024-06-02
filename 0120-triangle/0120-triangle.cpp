class Solution {
public:
     int findMin(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp)
     {
        if(i==n)
        { 
           return triangle[i][j];
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        int bottom=triangle[i][j]+findMin(i+1,j,triangle,n,dp);
        int bRight=triangle[i][j]+findMin(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(bottom,bRight);
     }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
         dp[n-1][i]=triangle[n-1][i];
        // return findMin(0,0,triangle,n-1,dp);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                   int bottom=triangle[i][j]+dp[i+1][j];
                   int bRight=triangle[i][j]+dp[i+1][j+1];
                   dp[i][j]=min(bottom,bRight);
            }
        }
        return dp[0][0];
    }
};