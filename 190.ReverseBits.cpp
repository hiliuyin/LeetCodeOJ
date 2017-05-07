/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

// Solution 1:
uint32_t reverseBits(uint32_t n) {
    const std::vector<int> reversedMap = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    return (reversedMap[n & 0xF] << 28)      | (reversedMap[(n>>4) & 0xF] << 24)
         | (reversedMap[(n>>8) & 0xF] << 20) | (reversedMap[(n>>12) & 0xF] << 16)
         | (reversedMap[(n>>16) & 0xF] << 12)| (reversedMap[(n>>20) & 0xF] << 8)
         | (reversedMap[(n>>24) & 0xF] << 4) | (reversedMap[(n>>28) & 0xF]);
}

// Solution 2: for 8 bit binary number abcdefgh, the process is as follow: abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}
