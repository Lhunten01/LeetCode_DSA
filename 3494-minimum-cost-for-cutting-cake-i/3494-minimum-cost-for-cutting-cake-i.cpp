class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x=horizontalCut.size();
        int y=verticalCut.size();
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>{});
        sort(verticalCut.begin(),verticalCut.end(),greater<int>{});
        int i=0,j=0;
        int vertical=1,horizontal=1;
        int cost=0;
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