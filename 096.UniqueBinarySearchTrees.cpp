/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// Dynamic Programming
int numTrees(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    auto p = new int[n+1];
    p[0] = 1;
    p[1] = 1;
    for (int k = 2; k <= n; ++k)
    {
        p[k] = 0;
        for (int i = 1; i <= k; ++i)
        {
            p[k] += p[i-1] * p[k-i];
        }
    }
    return p[n];
}
