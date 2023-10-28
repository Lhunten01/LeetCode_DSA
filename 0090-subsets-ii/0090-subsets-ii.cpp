class Solution {
public:
 void subsets(int index,vector<int>& nums,vector<int>temp,set<vector<int>>& st)
 {
     if(index>=nums.size())
     {
         sort(temp.begin(),temp.end());
         st.insert(temp);
         return;
     }
     subsets(index+1,nums,temp,st);
     temp.push_back(nums[index]);
     subsets(index+1,nums,temp,st);
 }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
      subsets(0,nums,temp,st);
       vector<vector<int>>ans;
       ans.insert(ans.begin(),st.begin(),st.end());
       return ans;
    }
};