class Solution {
public:
     int lcs(string text1, string text2,int i,int j, vector<vector<int>>&dp)
     {
         if(i==0||j==0)
         return 0;
         if(dp[i][j]!=-1)
         return dp[i][j];
        if(text1[i-1]==text2[j-1])
          dp[i][j]= 1+lcs(text1,text2,i-1,j-1,dp);     
         else 
         dp[i][j]=max(lcs(text1,text2,i-1,j,dp),lcs(text1,text2,i,j-1,dp));
         return dp[i][j];
     }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
      vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
      for(int j=0;j<=n2;j++)
      {
        dp[0][j]=0;
      }
       for(int j=0;j<=n1;j++)
      {
        dp[j][0]=0;
      }
       for(int i=1;i<=n1;i++)
       {
        for(int j=1;j<=n2;j++)
        {
         if(text1[i-1]==text2[j-1])
          dp[i][j]= 1+dp[i-1][j-1];
         else 
         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
       }
      return dp[n1][n2];
    }
};