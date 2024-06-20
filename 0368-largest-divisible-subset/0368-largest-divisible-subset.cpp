class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1),hash(n+1,1);
        for(int i=0;i<n;i++)
        {  hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0&&dp[prev]+1>dp[i])
                {dp[i]=dp[prev]+1;
                hash[i]=prev;
                }
            }
        }
     int ans=-1;
     int lastindex=-1;
     for(int i=0;i<n;i++)
     {
        if(dp[i]>ans)
        {
            ans=dp[i];
            lastindex=i;
        }
     }
      vector<int>lcs;
       lcs.push_back(nums[lastindex]);
       while(hash[lastindex]!=lastindex)
       {
           lastindex=hash[lastindex];
           lcs.push_back(nums[lastindex]);
       }
       reverse(lcs.begin(),lcs.end());
       return lcs;
    }
};