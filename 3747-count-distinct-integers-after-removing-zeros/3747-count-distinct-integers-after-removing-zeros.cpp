class Solution {
public:
    long long mypow(long long a,long long b){
        long long r=1;
        while(b){
            if(b&1) r*=a;
            a*=a;
            b>>=1;
        }
        return r;
    }

    long long countSameLengthNoZero(string s){
        int L = s.size();
        long long ans = 0;

        for(int i = 0; i < L; i++){
            int d = s[i] - '0';

            // first position cannot be zero
            int start = (i == 0 ? 1 : 0);

            for(int x = start; x < d; x++){
                if(x == 0) continue;
                ans += mypow(9, L - i - 1);
            }

            if(d == 0) 
                return ans;  // no further valid numbers
        }

        // If s itself has NO zero, count it
        bool ok = true;
        for(char c : s)
            if(c == '0') ok = false;

        if(ok) ans++;

        return ans;
    }

    long long countDistinct(long long n) {
        string s = to_string(n);
        int l = s.length();
        long long ans = 0;

        // count all numbers of smaller length
        for(int len = 1; len < l; len++){
            ans += mypow(9, len);
        }

        // count numbers of same length
        ans += countSameLengthNoZero(s);

        return ans;
    }
};
