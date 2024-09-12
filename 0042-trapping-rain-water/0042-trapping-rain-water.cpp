class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        int suffix[n];
        int prefix[n];
        prefix[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--)
        {
            suffix[j]=max(suffix[j+1],height[j]);
        }
        for(int k=0;k<n;k++)
        {
            sum+=min(prefix[k],suffix[k])-height[k];
        }
        return sum;
    }
};