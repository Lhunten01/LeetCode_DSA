class Solution {
public:
  long long int findHour(vector<int>&piles,int h)
  {
    int n=piles.size();
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
         sum+=ceil(((double)piles[i])/(double)(h));
    }
    return sum;
  }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        
        int low=1;
        int high=maxi;
        while(low<=high)
        {
            int mid=(high+low)/2;
            long long int sum=findHour(piles,mid);
            if(sum<=h)
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
   return low;
    }
};