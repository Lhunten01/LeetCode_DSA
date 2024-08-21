class Solution {
public:
     void giveSubset(int i,vector<int>&nums,set<vector<int>>&ans,vector<int>&temp)
     {
        if(i==nums.size())
        {
            ans.insert(temp);
            return;
        }
        giveSubset(i+1,nums,ans,temp);
        temp.push_back(nums[i]);
        giveSubset(i+1,nums,ans,temp);
        temp.pop_back();
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        vector<vector<int>>sol;
        sort(nums.begin(),nums.end());
        giveSubset(0,nums,ans,temp);
        sol.assign(ans.begin(),ans.end());
        return sol;
    }
};