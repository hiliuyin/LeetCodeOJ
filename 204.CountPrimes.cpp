/*
Description:
Count the number of prime numbers less than a non-negative number, n.
*/

int countPrimes(int n)
{
    auto isPrimes = new int[n];
    for (int i = 2; i < n; ++i)
        isPrimes[i] = 1;
    
    for (int i = 2; i*i < n; ++i)
    {
        if (isPrimes[i] == 0)
            continue;
        
        for (int j = i*i; j < n; j += i)
        {
            isPrimes[j] = 0;
        }
    }
    
    int count = 0;
    for (int i = 2; i < n; ++i)
    {
        if (isPrimes[i] == 1)
            count++;
    }
    
    return count;
}
