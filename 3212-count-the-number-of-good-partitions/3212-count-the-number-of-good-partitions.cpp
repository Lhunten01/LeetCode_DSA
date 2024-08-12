class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int>mp;
        int m=1e9+7;
        int n=nums.size();
        for(int i=0;i<n;i++)
        mp[nums[i]]=i;
        int i=0;
        int j=mp[nums[0]];
        int sum=1;
        while(i<n)
        { 
           if(j<i)
           sum=(sum*2)%m;
           j=max(j,mp[nums[i]]);
           i++;
        }
        return sum%(m); 

       
    }
};