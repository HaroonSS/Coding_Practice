class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // Iterate through all 32 bits of an integer
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;

            // Count how many numbers have the i-th bit set
            for (int num : nums) {
                if (num & (1 << i)) {
                    bitCount++;
                }
            }

            // If bitCount is not divisible by 3, this bit belongs to the unique number
            if (bitCount % 3 != 0) {
                result |= (1 << i); // Set the i-th bit in the result
            }
        }

        return result;
    }
};
