class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums1.size();
        // int m = nums2.size();

        // int i = 0;
        // int j = 0;
        // vector<int> ans;

        // while (i < n && j < m) {
        //     if (nums1[i] < nums2[j]) {
        //         ans.push_back(nums1[i]);
        //         i++;
        //     } else {
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while (i < n) {
        //     ans.push_back(nums1[i]);
        //     i++;
        // }

        // while (j < m) {
        //     ans.push_back(nums2[j]);
        //     j++;
        // }

        // int total = ans.size();

        // if (total % 2 == 1) {
        //     return ans[total / 2];
        // }

        // return (ans[total / 2] + ans[total / 2 - 1]) / 2.0;

        // Binary Seach: TC - O(log min(n, m))
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + (double)min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};
