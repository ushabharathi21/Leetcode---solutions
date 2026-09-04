
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int hash[256] = {0};

        int l = 0;
        int r = 0;
        int minlen = 1e9;
        int sIndex = -1;
        int cnt = 0;

        // Store the frequency of characters in t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        // Sliding window
        while (r < n) {

            // If s[r] is required in t
            if (hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            // When the window contains all characters of t
            while (cnt == m) {

                // Update minimum window
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }

                // Remove the left character
                hash[s[l]]++;

                // If removing it makes the window invalid
                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        // No valid window found
        if (sIndex == -1) {
            return "";
        }

        return s.substr(sIndex, minlen);
    }
};