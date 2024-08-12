class Solution {
public:
     void subsets(int i,vector<vector<int>>&ans,vector<int>&col,vector<int>&nums)
     {
        if(i==nums.size())
       { ans.push_back(col);
       return ;
       }
       subsets(i+1,ans,col,nums);
       
       col.push_back(nums[i]);
       subsets(i+1,ans,col,nums);
       col.pop_back();
     }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>col;
      subsets(0,ans,col,nums);
      return ans;
    }
};