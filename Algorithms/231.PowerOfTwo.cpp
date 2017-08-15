/*
Given an integer, write a function to determine if it is a power of two.
*/

// solution 1
bool isPowerOfTwo(int n)
{
    if (n == 0) return false;
    while (n != 0)
    {
        int bit = n&1;
        n >>= 1;
        if (bit == 1 && n != 0)
            return false;
    }
    return true;
}

// solution 2
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n-1)) == 0;
}

