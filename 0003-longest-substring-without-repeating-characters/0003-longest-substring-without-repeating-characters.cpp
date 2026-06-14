class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> count(128);
        for(int i=0, r=0; r<s.length(); ++r){
            ++count[s[r]];
            while(count[s[r]]>1)
            --count[s[i++]];
            ans = max(ans,r-i + 1);

        }
        return ans;
        
    }
};