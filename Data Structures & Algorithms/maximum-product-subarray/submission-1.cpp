class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int pro = nums[0];
        int minPro = nums[0];
        int maxPro = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(pro, minPro);
            }

            pro = max(nums[i], pro * nums[i]);
            minPro = min(nums[i], minPro * nums[i]);

            maxPro = max(maxPro, pro);
        }

        return maxPro;
    }
};
