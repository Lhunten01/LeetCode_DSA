class Solution {
public:
       int checkEdit(int i,int j,string word1,string word2,vector<vector<int>>&dp)
       { 
          if(i<0)
          return j+1;
          if(j<0)
          return i+1;
          if(dp[i][j]!=-1)
          return dp[i][j];
          if(word1[i]==word2[j])
          return  dp[i][j]=checkEdit(i-1,j-1,word1,word2,dp);
          else
          {
            return dp[i][j]=1+min({checkEdit(i-1,j-1,word1,word2,dp),checkEdit(i-1,j,word1,word2,dp),checkEdit(i,j-1,word1,word2,dp)});
          }
          return 0;
       }
    int minDistance(string word1, string word2) {
          int n=word1.length();
          int m=word2.length();
          vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
          return checkEdit(n,m,word1,word2,dp);
    }
};