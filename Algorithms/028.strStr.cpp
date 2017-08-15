/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(string haystack, string needle) {
    std::size_t size1 = haystack.size();
    std::size_t size2 = needle.size();
    
    if (size1 < size2) return -1;
    if (size1 == size2) return (haystack == needle) ? 0 : -1;
    for (int i = 0, iEnd = (int)(size1-size2+1); i < iEnd; ++i) {
        if (haystack.compare(i, size2, needle) == 0)
            return i;
    }
    return -1;
}

// solution 2: use std::string APIs
int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;
    if (needle.empty()) return 0;
    int pos = 0, posEnd = haystack.size() - needle.size() + 1;
    while (pos < posEnd) {
        pos = haystack.find_first_of(needle.front(), pos);
        if (pos == std::string::npos) return -1;
        if (haystack.size() - pos + 1 < needle.size()) return -1;
        if (haystack.substr(pos, needle.size()) == needle) return pos;
        pos++;
    }
    return -1;
}
