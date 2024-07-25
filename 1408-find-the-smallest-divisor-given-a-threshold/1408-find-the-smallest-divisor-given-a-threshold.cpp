class Solution {
public:
    bool checkDiv(vector<int>&nums,int mid,int threshold)
    { int count=0;
        for(int i=0;i<nums.size();i++)
        {
           count+=ceil((double)(nums[i])/(double)(mid));
        }
        return count<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high=*max_element(nums.begin(),nums.end());
        int low=1;
        while(low<=high)
        {
             int mid=low+((high-low)/2);
             if(checkDiv(nums,mid,threshold))
                high=mid-1;
             else
               low=mid+1;   
        }
        return low; 
    }
};