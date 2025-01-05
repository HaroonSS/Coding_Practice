class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0; // Initialize the reversed number as 0
        for (int i = 0; i < 32; i++) {
            // Extract the least significant bit of n
            int bit = n & 1;
            // Shift the result left and add the extracted bit
            result = (result << 1) | bit;
            // Shift n to the right to process the next bit
            n >>= 1;
        }
        return result; // Return the reversed number
    }
};
