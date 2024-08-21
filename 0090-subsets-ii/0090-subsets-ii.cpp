class Solution {
public:
     void giveSubset(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp)
     {   
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
        if(index!=i&&nums[i]==nums[i-1])
        continue;
        temp.push_back(nums[i]);
        giveSubset(i+1,nums,ans,temp);
        temp.pop_back();
        }
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp={ };
        sort(nums.begin(),nums.end());
        giveSubset(0,nums,ans,temp);
        return ans;
    }
};