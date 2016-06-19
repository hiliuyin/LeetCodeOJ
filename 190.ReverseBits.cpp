/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

uint32_t reverseBits(uint32_t n)
{
    const std::vector<int> reversedMap = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    
    return (reversedMap[n & 0xF] << 28)      | (reversedMap[(n>>4) & 0xF] << 24)
         | (reversedMap[(n>>8) & 0xF] << 20) | (reversedMap[(n>>12) & 0xF] << 16)
         | (reversedMap[(n>>16) & 0xF] << 12)| (reversedMap[(n>>20) & 0xF] << 8)
         | (reversedMap[(n>>24) & 0xF] << 4) | (reversedMap[(n>>28) & 0xF]);
}
