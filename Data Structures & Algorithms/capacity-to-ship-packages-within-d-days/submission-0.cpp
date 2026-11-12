class Solution {
   public:
    int findMax(vector<int>& arr) {
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }

        return maxi;
    }

    int totalCapacity(vector<int>& arr, int cap) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (load + arr[i] > cap) {
                days++;
                load = arr[i];
            } else {
                load += arr[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long noOfDays = totalCapacity(weights, mid);
            if (noOfDays <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};