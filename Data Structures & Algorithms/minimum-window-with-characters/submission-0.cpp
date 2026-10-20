class Solution {
   public:
    string minWindow(string s, string t) {
        int low = 0;
        int count = 0;
        int start = 0;
        int res = INT_MAX;
        unordered_map<char, int> f;
        unordered_map<char, int> w;

        for (int i = 0; i < t.length(); i++) {
            f[t[i]]++;
        }

        for (int high = 0; high < s.length(); high++) {
            char ch = s[high];
            w[ch]++;

            if (f.count(ch) && w[ch] <= f[ch]) {
                count++;
            }

            while (count >= t.length()) {
                int len = high - low + 1;

                if (len < res) {
                    res = len;
                    start = low;
                }

                char left = s[low];
                w[left]--;

                if (f.count(left) && w[left] < f[left]) {
                    count--;
                }

                low++;
            }
        }

        return res == INT_MAX ? "" : s.substr(start, res);
    }
};
