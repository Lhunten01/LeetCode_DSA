class Solution {
public:
    int findMax(int i,vector<int>&prices,int buy,int k,vector<vector<vector<int>>> dp)
    {   if(i==prices.size()||k==0)
        return 0;
        if(dp[i][buy][k]!=-1)
        return dp[i][buy][k];
        long long profit=0;
        if(buy==0)
        profit=max(0+findMax(i+1,prices,0,k,dp),-prices[i]+findMax(i+1,prices,1,k,dp));
        if(buy==1)
        profit=max(0+findMax(i+1,prices,1,k,dp),+prices[i]+findMax(i+1,prices,0,--k,dp));

           return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
       for(int i=n-1;i>=0;i--)
       {
        for(int j=0;j<=1;j++)
        {
            for(int k=1;k<=2;k++)
            {
               
            if(j==0)
             dp[i][j][k]=max(0+dp[i+1][0][k],-prices[i]+dp[i+1][1][k]);
            if(j==1)
             dp[i][j][k]=max(0+dp[i+1][1][k],+prices[i]+dp[i+1][0][k-1]);
            }
        }
       }
       return dp[0][0][2];
    }
};