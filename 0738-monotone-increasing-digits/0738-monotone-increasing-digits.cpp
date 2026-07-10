class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);     
        int length = s.length();     
        if (length == 1) return n;

        int marker = length;
    
        for (int i = length - 1; i > 0; i--) {
            if (s[i] < s[i - 1]){
                marker = i;
                s[i - 1] = s[i - 1] - 1;  
            }
        }

        for (int i = marker; i < length; i++) {
            s[i] = '9';             
        }

        return stoi(s);             
    }
};
