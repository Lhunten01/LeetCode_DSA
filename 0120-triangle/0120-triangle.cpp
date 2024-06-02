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
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findMin(0,0,triangle,n-1,dp);
    }
};