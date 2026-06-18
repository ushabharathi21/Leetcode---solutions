class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.length(),cntA=0,cntB=0;
        for(auto c:s){
            if(c=='a')cntA++;
            else cntB++;
        }
        return abs(cntA-cntB);
    }
};