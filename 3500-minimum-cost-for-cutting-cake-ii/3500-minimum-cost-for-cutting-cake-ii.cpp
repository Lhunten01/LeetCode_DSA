class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
       long long x=horizontalCut.size();
        long long  y=verticalCut.size();
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>{});
        sort(verticalCut.begin(),verticalCut.end(),greater<int>{});
        int i=0,j=0;
        long long vertical=1,horizontal=1;
        long long cost=0;
        while(i<x&&j<y)
        {
            if(horizontalCut[i]<=verticalCut[j])
            {
              cost+=verticalCut[j]*horizontal;
              j++;
              vertical++;
            }
            else
            {
              cost+=horizontalCut[i]*vertical;
              i++;
              horizontal++;
            }
        }
        while(i<x)
        {
             cost+=horizontalCut[i]*vertical;
              i++;
              horizontal++;
        }
        while(j<y)
        {
            cost+=verticalCut[j]*horizontal;
              j++;
              vertical++;
        }
        return cost;
    }
};