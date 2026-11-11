class Solution {
   public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }

    long long countTotalHours(vector<int>& piles, int mid) {
        long long totalHours = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalHours += (piles[i] + mid - 1) / mid;
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long minH = countTotalHours(piles, mid);

            if (minH <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
