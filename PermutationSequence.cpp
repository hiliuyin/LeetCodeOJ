// Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.
// 
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
// 
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
// 
// Note: Given n will be between 1 and 9 inclusive.

// Refer to:
// http://wordaligned.org/articles/next-permutation.html
//
template <typename Iter>
bool nextPermutation(Iter first, Iter last)
{
    if (first == last) return false;
    
    Iter i = first;
    ++i;
    if (i == last) return false;
    
    i = last;
    --i;
    
    for (;;)
    {
        Iter ii = i;
        --i;
        
        if (*i < *ii)
        {
            Iter j = last;
            while (*i >= *--j) {}
            
            std::iter_swap(i, j);
            std::reverse(ii, last);
            return true;
        }
        
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}

std::string getPermutation(int n, int k)
{
    const std::string S("123456789");
    std::string str = S.substr(0, n);
    
    for (int i = 1; i < k; ++i)
    {
        nextPermutation(str.begin(), str.end());
    }
    
    return str;
}
