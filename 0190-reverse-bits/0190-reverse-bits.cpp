class Solution {
public:
    int reverseBits(uint32_t n) {
        uint32_t count=0;
        for(int i=0;i<32;i++){
            count<<=1;
            count|=(n&1);
            n>>=1;
        }
       return count;
    }
};