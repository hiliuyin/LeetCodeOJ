/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

// Solution 1: recursive solution
bool isPowerOfThree(int n)
{
    if (n == 0) return false;
    while (n%3 == 0)
        n /= 3;
    return n == 1;
}

// Solution 2:
bool isPowerOfThree(int n)
{
    const int maxPowOfThree = 1162261467;
    return n > 0 && maxPowOfThree%n == 0;
}

// Solution 3:
bool isPowerOfThree(int n)
{
    return std::fmod(std::log10(n)/std::log10(3), 1) == 0;
}
