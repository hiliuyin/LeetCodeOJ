/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

bool isPowerOfFour(int num) {
    if (num <= 0 || (num & (num-1)) != 0) return false;
    return (num & 0x55555555) != 0;
}
