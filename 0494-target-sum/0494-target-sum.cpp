class Solution {
public:
    int check(int i,vector<int>&nums,int target,vector<vector<int>>& dp)
    {  
      
        if(i==0)
        {
            if(nums[0]==target&&nums[0]==0)
            return 2;
            else if(target==0||nums[0]==target)
            return 1;
            else 
            return 0;
        }
        if(dp[i][target]!=-1)
        return dp[i][target];
        int notTake=check(i-1,nums,target,dp);
        int take=0;
        if(nums[i]<=target)
        take=check(i-1,nums,target-nums[i],dp);
        return dp[i][target]=notTake+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        
        if(totalSum-target<0||(totalSum-target)%2!=0)
        return 0;
        int newTarget=(totalSum-target)/2;
        vector<vector<int>>dp(n,vector<int>(newTarget+1,-1));
        return check(n-1,nums,newTarget,dp);
    }
};