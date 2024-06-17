class Solution {
public:
    int maxProfit(int l, vector<int>& prices) {
          int n=prices.size();
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(l+1, 0)));
       for(int i=n-1;i>=0;i--)
       {
        for(int j=0;j<=1;j++)
        {
            for(int k=1;k<=l;k++)
            {
               
            if(j==0)
             dp[i][j][k]=max(0+dp[i+1][0][k],-prices[i]+dp[i+1][1][k]);
            if(j==1)
             dp[i][j][k]=max(0+dp[i+1][1][k],+prices[i]+dp[i+1][0][k-1]);
            }
        }
       }
       return dp[0][0][l];
    }
};