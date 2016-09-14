/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:
Input:
8
Output:
3
Explanation:
8 -> 4 -> 2 -> 1
Example 2:
Input:
7
Output:
4
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

// solution 1: recursive solution
int integerReplacement(int n)
{
    std::function<int(long long)> helper = [&](long long k) -> int // must be long long, since n might be INT_MAX
    {
        if (k == 1) return 0;
        if (k == 2) return 1;
        if (k == 3) return 2;
        
        if (k%2 == 0)
            return helper(k/2) + 1;
        else
            return std::min(helper(k+1), helper(k-1)) + 1;
    };
        
    return helper(n);
}
