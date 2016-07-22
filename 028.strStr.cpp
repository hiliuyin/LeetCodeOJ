/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(string haystack, string needle)
{
    std::size_t size1 = haystack.size();
    std::size_t size2 = needle.size();
    
    if (size1 < size2) return -1;
    if (size1 == size2) return (haystack == needle) ? 0 : -1;
    for (int i = 0, iEnd = (int)(size1-size2+1); i < iEnd; ++i)
    {
        if (haystack.compare(i, size2, needle) == 0)
            return i;
    }
    return -1;
}
