class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        if (s[0] == '0') return 0;

        int prev2 = 1;            // dp[i-2]
        int prev1 = 1;            // dp[i-1], for i==0 it's 1 because s[0] != '0'

        for (int i = 1; i < n; ++i) {
            int cur = 0;
            int d1 = s[i] - '0';
            int d2 = (s[i-1] - '0') * 10 + d1;

            // single digit valid (not '0')
            if (d1 >= 1) cur += prev1;

            // two-digit valid (10..26)
            if (d2 >= 10 && d2 <= 26) cur += prev2;

            // if no valid decoding at this position -> overall invalid
            if (cur == 0) return 0;

            // shift window
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
