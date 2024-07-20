class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi=0;
       int min=prices[0];
       int n=prices.size();
       for(int i=1;i<n;i++)
       {
           if(prices[i]>=min)
           maxi=max(maxi,prices[i]-min);
           else
           min=prices[i];
       }
       return maxi;
    }
};