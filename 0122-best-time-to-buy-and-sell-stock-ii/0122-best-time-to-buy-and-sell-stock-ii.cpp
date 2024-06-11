class Solution {
public:
     int findMax(bool buy,int i,vector<int>&prices,int n,vector<vector<long>>&dp)
     {
        if(i==n)
         return 0;
         if(dp[i][buy]!=-1)
         return dp[i][buy];
         int profit=0;
         if(buy)
         {
            profit=max(prices[i]+findMax(!buy,i+1,prices,n,dp),findMax(buy,i+1,prices,n,dp));
         }
         else
         profit=max(-prices[i]+findMax(!buy,i+1,prices,n,dp),findMax(buy,i+1,prices,n,dp));
       return dp[i][buy]= profit;
     }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=false;
       vector<vector<long>> dp(n, vector<long>(2, -1));
        return findMax(buy,0,prices,n,dp);
    }
};