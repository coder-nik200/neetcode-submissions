class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if (k <= 1) {
            return 0;
        }

        int low = 0;
        int mul = 1;
        int res = 0;

        for (int high = 0; high < n; high++) {
            mul *= nums[high];

            while (mul >= k) {
                mul /= nums[low];
                low++;
            }

            res += high - low + 1;
        }

        return res;
    }
};