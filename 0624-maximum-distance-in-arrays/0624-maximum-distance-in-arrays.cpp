class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi=arrays[0].back();
        int mini=arrays[0].front();
        int ans=0;
        for(auto it:arrays)
        {  
        
            int x=it.front();
            int y=it.back();
            if(x==mini&&y==maxi)
            continue;
            ans=max(ans,abs(maxi-x));
            ans=max(ans,abs(y-mini));
            if(x<mini)
            {
                mini=x;
            }
           if(maxi<y)
            {
                maxi=y;
            }
                
        
        }
        return ans;
    }
};