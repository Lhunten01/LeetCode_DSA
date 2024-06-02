class Solution {
public:
     int numPath(int i,int j,vector<vector<int>>&dp)
     {  if(j<0||i<0)
         return 0;
        if(i==0&&j==0)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int top=numPath(i-1,j,dp);
        int left=numPath(i,j-1,dp);
        return dp[i][j]=top+left;

     }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return numPath(m-1,n-1,dp);
    }
};