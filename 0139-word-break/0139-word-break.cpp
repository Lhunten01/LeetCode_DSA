class Solution {
public:
    bool solve(int index,string s,set<string>st,vector<int>&dp)
    {
        if(index==s.length())
        return true;
        if(dp[index]!=-1)
        return dp[index];
        for(int i=index+1;i<=s.length();i++)
        { 
            if(st.find(s.substr(index,i-index))!=st.end())
            {
                  if(solve(i,s,st,dp))
                  return dp[index]=true;
            }
        }
      return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        int n=wordDict.size();
         vector<int>dp(s.length()+1,-1);
        int m=s.length();

        for(int i=0;i<n;i++)
        {
            st.insert(wordDict[i]);
        }

        if(st.find(s)!=st.end())
        return true;

      return solve(0,s,st,dp);
        
    }
};