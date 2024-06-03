#include <vector>
#include <numeric>

class Solution {
public:
    bool dpcheck(vector<int>& nums, int n, int target, vector<vector<int>>& memo) {
        if (target == 0)
            return true;
        if (n == 0)
            return nums[0] == target;

        if (memo[n][target] != -1)
            return memo[n][target];

        int taken = 0;
        int nottaken = 0;
        nottaken = dpcheck(nums, n - 1, target, memo);
        if (nums[n] <= target)
        taken = dpcheck(nums, n - 1, target - nums[n], memo);

        memo[n][target] = taken || nottaken;
        return memo[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> memo(n, vector<bool>(target + 1,0));
         memo[0][nums[0]]==true;
         for(int i=0;i<n;i++)
         if(nums[0]<=target)
         memo[i][0]=true;
         for(int i=1;i<n;i++)
         {
            for(int j=0;j<=target;j++)
            {
                 bool taken = false;
                bool nottaken = false;
               nottaken = memo[i-1][j];
              if (nums[i] <= j)
              taken = memo[i-1][j-nums[i]];

             memo[i][j] = taken || nottaken;
            }
         }
    return memo[n-1][target];
        // return dpcheck(nums, n - 1, target, memo);

    }
};
