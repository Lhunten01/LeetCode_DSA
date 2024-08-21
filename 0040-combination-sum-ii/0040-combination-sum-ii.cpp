class Solution {
public:
   void findSub(int i,vector<vector<int>>&ls,vector<int>&ans,vector<int>&candidates,int target)
   {  int n=candidates.size();
    
        if(target==0)
        { ls.push_back(ans);
           return;
        }
        
    for(int index=i;index<n;index++)
    { if(index!=i&&candidates[index]==candidates[index-1])
       continue;
       if(candidates[index]>target)
       break;
       
        ans.push_back(candidates[index]);
        findSub(index+1,ls,ans,candidates,target-candidates[index]);
        ans.pop_back();
}
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        vector<vector<int>>ls;
        int n=candidates.size();
        findSub(0,ls,ans,candidates,target);
        return ls;
    }
};