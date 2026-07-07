class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;  
        int l = 0;  

        while (i < n) {
        
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

           
            if (l != 0)
                s[l++] = ' ';

            int start = l;

           
            while (i < n && s[i] != ' ') {
                s[l++] = s[i++];
            }

            
            reverse(s.begin() + start, s.begin() + l);
        }

        // Remove extra characters at the end
        s.resize(l);

        return s;
    }
};