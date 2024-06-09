class Solution {
public:
    int countCoin(int i,vector<int>&coins,int amount,vector<vector<int>>&dp)
     {
        if(i==0)
        {
            if(amount%coins[i]==0)
            return amount/coins[0];
            else
            return 1e9;
        }
        if(dp[i][amount]!=-1)
        return dp[i][amount];
        int noTake=countCoin(i-1,coins,amount,dp);
        int take=1e9;
        if(coins[i]<=amount)
        {
            take=1+min(countCoin(i-1,coins,amount-coins[i],dp),countCoin(i,coins,amount-coins[i],dp));
        }
        return dp[i][amount]=min(take,noTake);
     }
    int coinChange(vector<int>& coins,int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int x= countCoin(n-1,coins,amount,dp);
        return x==1e9?-1:x;
        
    }
};