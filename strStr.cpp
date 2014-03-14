// Implement strStr().
// 
// Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
//

char *strStr(char *haystack, char *needle)
{
    if (haystack == nullptr || needle == nullptr)
        return nullptr;
    if (*needle == '\0')
        return haystack;
    
    char *pAdv = haystack;
    char *q = needle;
    while(*++q != '\0')
        ++pAdv;

    char *p = haystack;
    while (*pAdv != '\0')
    {
        char *qq = needle;
        char *pp = p;
        while (*pp != '\0' && *qq != '\0' && *qq == *pp)
        {
            ++qq;
            ++pp;
        }
        
        if (*qq == '\0')
            return p;
        
        ++p;
        ++pAdv;
    }
    
    return nullptr;
}
