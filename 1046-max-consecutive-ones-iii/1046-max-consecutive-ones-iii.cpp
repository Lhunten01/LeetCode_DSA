class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int ans=0;
        while(i<n)
        { 
            if(nums[i]==1)
            {
                ans=max(ans,i-j+1);
                i++;
            }
            else
            {
                if(k>0)
                {
                    k--;
                    ans=max(ans,i-j+1);
                    i++;
                }
                else
                {
                    if(nums[j]==0)
                    k++;
                    j++;
                }
            }
        }
        return ans;
    }
};