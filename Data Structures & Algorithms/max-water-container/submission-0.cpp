class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxWater = 0;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int width = j - i;
            int h = min(heights[i], heights[j]);
            int currWater = width * h;
            maxWater = max(maxWater, currWater);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxWater;
    }
};
