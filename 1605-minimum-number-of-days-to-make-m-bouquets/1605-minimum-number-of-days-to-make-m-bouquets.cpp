class Solution {
public:
   bool makBou(int mid,vector<int>&bloomDay,int m,int k)
   {
      int n=bloomDay.size();
      int count=0;
      int check=0;
      for(int i=0;i<n;i++)
      {
         if(bloomDay[i]<=mid)
         count++;
         else
         {
          check+=count/k; 
          count=0;
         }
      }
      check+=count/k;
      return m<=check;
      
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long int)m*k>n)
        return -1;
       int high=*max_element(bloomDay.begin(),bloomDay.end());
       int low=*min_element(bloomDay.begin(),bloomDay.end());
       int mini=INT_MAX;
       while(low<=high)
       {
        int mid=(low+high)/2;
        if(makBou(mid,bloomDay,m,k))
        {
            high=mid-1;
        }
        else
         low=mid+1;
       }
       return low;
    }
};
 