class Solution {
public:
      void find(vector<int> nums,vector<vector<int>>&ans,int index,vector<int>takein)
      {
          if(index>=nums.size()){//base case
          ans.push_back(takein);
          return;
          }

          find(nums,ans,index+1,takein);//exclude

          int x=nums[index];//include
          takein.push_back(x);
          find(nums,ans,index+1,takein);
      }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>takein;
        int index=0;
        find(nums,ans,index,takein);
        return ans;
    }
};