class Solution {
public:
    int findLIS(int i,vector<int>& nums,int prev,int n,vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        int notTake=0,take=0;
        notTake=findLIS(i+1,nums,prev,n,dp);
        if(prev==-1||nums[prev]<nums[i])
        take=findLIS(i+1,nums,i,n,dp)+1;
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return findLIS(0,nums,-1,n,dp);
    }
};