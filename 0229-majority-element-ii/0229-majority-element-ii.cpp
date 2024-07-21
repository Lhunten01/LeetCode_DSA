class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int t=n/3;
        int t1=INT_MAX,t2=INT_MAX,c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
             if(c1==0&&nums[i]!=t2)
             {
                t1=nums[i];
                c1++;
             }
             else if(c2==0&&nums[i]!=t1)
             {
                t2=nums[i];
                c2++;
             }
             else if(nums[i]==t1)
             {
                c1++;
             }
             else if(nums[i]==t2)
             {
                c2++;
             }
             else if(nums[i]!=t1&&nums[i]!=t2)
             {
                c1--;
                c2--;
             }
        }
        c1=0,c2=0;
        vector<int>ans;
      for(int i=0;i<n;i++)
      {
        if(nums[i]==t1)
        c1++;
        if(nums[i]==t2)
        c2++;
      }
      if(c1>t)
     ans.push_back(t1);
     if(c2>t)
     ans.push_back(t2);
     return ans;
    }
};