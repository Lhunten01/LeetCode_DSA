class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
      for(int i=0;i<n;i++) 
      {
        int l=i+1;
        int r=n-1;
       while(l<r)
       { int sum=nums[i]+nums[l]+nums[r];
        if(sum>0)
        {
            r--;
        }
        else if(sum<0)
        {
            l++;
        }
        else {
            vector<int>t={nums[i],nums[l],nums[r]};
            ans.insert(t);
            l++;
            r--;
        }
       }
      } 
      vector<vector<int>>sol;
      sol.assign(ans.begin(),ans.end());
      return sol;
    }
};