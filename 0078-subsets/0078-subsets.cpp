class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sol;
        int n=nums.size();
        for(int i=0;i<pow(2,n);i++)
        {
           vector<int>temp;
           for(int j=0;j<n;j++)
           {
             if(i&1<<j)
              temp.push_back(nums[j]);
           }
           sol.push_back(temp);
        }
        return sol;
    }
};