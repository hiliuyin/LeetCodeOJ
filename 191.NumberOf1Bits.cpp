/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

// Solution 1: iterative solution
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        n &= (n-1);
        ++count;
    }
    return count;
}

// Solution 2: divide and conquer, from wikipedia
int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + (n >> 1 & 0x55555555);
    n = (n & 0x33333333) + (n >> 2 & 0x33333333);
    n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
    n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
    return n;
}
