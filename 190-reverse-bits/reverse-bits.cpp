class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t resBin = 0;
        for(int i=0;i<32;i++){
            int lastBit = n&1;
            resBin = resBin << 1;
            resBin = resBin | lastBit;
            n = n >> 1;
        }
        return resBin;
    }
};