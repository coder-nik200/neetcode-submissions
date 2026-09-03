class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int col = 0; col < cols; col++) {
            int low = 0;
            int high = rows - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (matrix[mid][col] == target) {
                    return true;
                }

                if (matrix[mid][col] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};