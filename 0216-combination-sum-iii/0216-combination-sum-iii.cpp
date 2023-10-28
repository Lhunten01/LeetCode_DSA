class Solution {
public:
  void sum3(int index,int k,int n,vector<int>temp,set<vector<int>>&st)
  {
      if(temp.size()==k||index>=10)
      {
          int x=accumulate(temp.begin(),temp.end(),0);
          if(x==n&&temp.size()==k)
          {
              sort(temp.begin(),temp.end());
              st.insert(temp);
              return;
          }
          else
          {
              return;
          }
      }
      sum3(index+1,k,n,temp,st);
      temp.push_back(index);
      sum3(index+1,k,n,temp,st);
  }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>>st;
        vector<int>temp;
         sum3(1,k,n,temp,st);
       vector<vector<int>>ans;
       ans.insert(ans.begin(),st.begin(),st.end());
       return ans;
    }
};