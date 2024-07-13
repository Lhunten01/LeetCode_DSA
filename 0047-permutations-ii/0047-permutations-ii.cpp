class Solution {
public:
   void permute(vector<int>& nums,int l,int r,set<vector<int>>&st)
   {
    if(l==r)
    st.insert(nums);
    for(int i=l;i<r;i++)
    {
        swap(nums[i],nums[l]);
        permute(nums,l+1,r,st);
        swap(nums[i],nums[l]);
    }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>x;
        int n=nums.size();
        permute(nums,0,n,st);
        x.assign(st.begin(), st.end());
       return x;
    
    }
};