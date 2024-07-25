class Solution {
public:
      bool check(vector<int>& nums,int mid,int k)
    {
        int count=1;
        int tempsum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(tempsum+nums[i]>mid)
            {
                count++;
                tempsum=nums[i];
                if(count>k)
                return false;
            }
            else
             tempsum+=nums[i];
        }
       return count<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int high=accumulate(nums.begin(),nums.end(),0);
        int low=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            if(check(nums,mid,k)) 
                {   
                    high=mid-1;
                }
             else
                low=mid+1;
        }
        return low;
    }
};