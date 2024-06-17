class Solution {
public:
    int maxEarn(int i, long buy,vector<int>& prices,int n,vector<vector<long>>&dp)
    {
        if(i==n)
        {
            return 0;
        }
        long long profit=0;
         if(dp[i][buy]!=-1)
         return dp[i][buy];
        if(buy==1)
        {
           profit=max(0+maxEarn(i+1,1,prices,n,dp),+prices[i]+maxEarn(i+1,0,prices,n,dp));
        }
        if(buy==0)
           profit=max(0+maxEarn(i+1,0,prices,n,dp),-prices[i]+maxEarn(i+1,1,prices,n,dp));

         return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, -1));
        dp[n][0] = dp[n][1] = 0;
         for(int i=n-1;i>=0;i--)
         {long long profit=0;
            for(int j=0;j<=1;j++)
            {
                
           if(j==1)     
           profit=max(0+dp[i+1][1],+prices[i]+dp[i+1][0]);
           if(j==0)
           profit=max(0+dp[i+1][0],-prices[i]+dp[i+1][1]);
           dp[i][j]=profit;
            }
             
         }
       return dp[0][0];
    }
};