/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

// 只需考虑5的个数，5, 25, 125....
int trailingZeroes(int n) 
{
    long long base = 5; // 防止溢出
    int zeros = 0;
    while (n >= base)
    {
        zeros += n/base;
        base *= 5;
    }
    return zeros;
}
