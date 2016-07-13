/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

int countNumbersWithUniqueDigits(int n)
{
    if (n == 0) return 1;
    std::function<int(int)> countHelper = [&](int k) -> int
    {
        if (k == 1) return 10;
        if (k > 10) k = 10;
        int num = 9;
        for (int i = 0; i < (k-1); ++i)
            num *= (9-i);
        return num + countHelper(k-1);
    };
    
    return countHelper(n);
}
