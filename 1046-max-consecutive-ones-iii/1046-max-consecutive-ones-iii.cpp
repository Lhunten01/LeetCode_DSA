class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int right = 0, left = 0;
        int n = nums.size();

        while (right < n) {
            if (nums[right] == 1) {
                count = max(count, right - left + 1);
                right++;
            } else {
                if (k > 0) {
                    k--;
                    count = max(count, right - left + 1);
                    right++;
                } else {
                    if (nums[left] == 0) {
                        k++;
                    }
                    left++;
                }
            }
        }

        return count;
    }
};
