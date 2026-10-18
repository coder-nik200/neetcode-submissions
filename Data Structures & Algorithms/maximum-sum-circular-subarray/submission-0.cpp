class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMaxSum = nums[0];
        int curMinSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // MaxSum
            curMaxSum = max(nums[i], curMaxSum + nums[i]);
            maxSum = max(maxSum, curMaxSum);

            // MinSum
            curMinSum = min(nums[i], curMinSum + nums[i]);
            minSum = min(minSum, curMinSum);

            totalSum += nums[i];
        }

        int circularSum = totalSum - minSum;

        if (circularSum == 0) {
            return maxSum;
        }

        return max(circularSum, maxSum);
    }
};