/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows.
How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

int reverse(int x)
{
    int sign = (x >= 0) ? 1 : -1;
    long long xCopy = std::abs(x);
    long long dummy = 0;
    while (xCopy != 0)
    {
        dummy = dummy * 10 + xCopy % 10;
        xCopy /= 10;
    }
    dummy = sign * dummy;

    if (dummy < INT_MIN || dummy > INT_MAX)
        return 0;
    
    return static_cast<int>(dummy);
}

