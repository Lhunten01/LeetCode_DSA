class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      int n=arr.size();
      int mod=1000000007;
      unordered_map<int,long long>mp;
      mp[arr[0]]=1;
      for(int i=1;i<n;i++)
      {  
          mp[arr[i]]=1;
          for(int j=0;j<i;j++)
          {  int x=arr[j];
              if(arr[i]%x==0 && mp.find(arr[i]/x)!=mp.end())
              {
                mp[arr[i]]=(mp[arr[i]]+(mp[x]*mp[arr[i]/x])%mod)%mod;
              }
          }
      }
      long long count=0;
     for(auto it:mp)
     {   cout<<it.first<<" "<<it.second<<endl;
         count=(count+it.second)%mod;
     }
     return count;
    }
};

