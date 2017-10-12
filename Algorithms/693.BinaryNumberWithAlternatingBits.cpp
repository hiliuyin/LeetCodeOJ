/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.

Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.

Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
*/

bool hasAlternatingBits(int n) {
    const int mask1 = 0xAAAAAAAA;
    const int mask2 = 0x55555555;
    
    int m = n;
    int allOnes = 0;
    while (m != 0) {
        m >>= 1;
        allOnes <<= 1;
        allOnes += 1;
    }
    
    return (n ^ (mask1 & allOnes)) == 0 || (n ^ (mask2 & allOnes)) == 0;
}
