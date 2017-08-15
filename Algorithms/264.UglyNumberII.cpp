/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

// Solution 1: 
int nthUglyNumber(int n)
{
    if (n == 1) return 1;
    
    std::vector<int> v{1};
    
    for (int i = 2; i <= n; ++i)
    {
        int val1 = *std::find_if(v.begin(), v.end(), [&](int val){ return val*2 > v.back(); }) * 2;
        int val2 = *std::find_if(v.begin(), v.end(), [&](int val){ return val*3 > v.back(); }) * 3;
        int val3 = *std::find_if(v.begin(), v.end(), [&](int val){ return val*5 > v.back(); }) * 5;
        
        v.emplace_back(std::min(std::min(val1, val2), val3));
    }
    
    return v[n-1];
}

