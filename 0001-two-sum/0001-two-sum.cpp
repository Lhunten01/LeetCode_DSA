class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
        
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end())
            {
               ans.push_back(i);
               ans.push_back(mp[rem]);
               break;
            }
          mp[nums[i]]=i;
        }
        return ans;
    }
};