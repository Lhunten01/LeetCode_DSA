class Solution {
public:
    void findCombination(int index,int k,int n,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(n==0&&temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<10;i++)
        {  if(i==index)
           continue;
            if(i<=n)
            {temp.push_back(i);
            findCombination(i,k,n-i,ans,temp);
            temp.pop_back(); } 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans;
       vector<int>temp;
       findCombination(0,k,n,ans,temp);
       return ans;
    }
};