class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            int count=0;
            while(i<n&&nums[i]==1)
            {
                count++;
                i++;
            }
            maxi=max(maxi,count);
            i++;
        }
        return maxi;
    }
};