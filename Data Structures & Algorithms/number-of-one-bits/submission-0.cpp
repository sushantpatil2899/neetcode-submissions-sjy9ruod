class Solution {
public:
    int hammingWeight(uint32_t n) {
        int set_bits= 0;
        while (n>0) {
            if (n & 1) set_bits = set_bits + 1;
            n = n >> 1;
        }

        return set_bits;
    }
};
