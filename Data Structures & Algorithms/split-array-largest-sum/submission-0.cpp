class Solution {
   public:
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    int splitArraySum(vector<int>& nums, long long maxSum) {
        int sumArrayCount = 1;
        long long sumArray = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sumArray + nums[i] <= maxSum) {
                sumArray += nums[i];
            } else {
                sumArrayCount++;
                sumArray = nums[i];
            }
        }

        return sumArrayCount;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = findMax(nums);
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int requiredArray = splitArraySum(nums, mid);
            if (requiredArray <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};