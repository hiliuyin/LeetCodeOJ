/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).

Example 1:
Input:
3
Output:
3

Example 2:
Input:
11
Output:
0
Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

int findNthDigit(int n) {
    if (n <= 9) return n;
    
    // step 1: calculate the range, that is the digits
    int digits = 1;
    long base = 9;
    while (n > digits * base) {
        n -= digits * base;
        base *= 10;
        digits++;
    }
    
    // step 2: find what is the target number
    int start = std::pow(10, digits - 1); 
    int offset = (n - 1) / digits;
    int num = start + offset; // num is the target number
    
    // step 3: find which digit is the answer
    num /= std::pow(10, n%digits == 0 ? 0 : (digits - n%digits));
    return num % 10;
}
