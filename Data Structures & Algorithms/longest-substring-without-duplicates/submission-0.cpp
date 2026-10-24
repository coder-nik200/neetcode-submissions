class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int low = 0;
        int res = 0;
        unordered_map<char, int> f;

        for (int high = 0; high < n; high++) {
            f[s[high]]++;

            while (f[s[high]] > 1) {
                f[s[low]]--;

                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};
