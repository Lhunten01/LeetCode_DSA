class Solution {
public:
     bool findQuan(vector<int>&nums, int mid,int days)
     {  int n=nums.size();
     int count=0;
     int day=1;
        for(int i=0;i<n;i++)
        {
           if(count+nums[i]>mid)
           { 
            count=nums[i];
            day++; 
           }
           else
           { 
               count+=nums[i];
           }
        }  
        
        return day<=days;
     }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(),0);
        int low=*max_element(weights.begin(),weights.end());
        int ans=INT_MAX;
        while(low<=high)
        {
          int mid=low+((high-low)/2);
          if(findQuan(weights,mid,days))
         { high=mid-1;
           ans=min(ans,mid);
         }
          else
          low=mid+1;
        }
        return ans;
    }
};