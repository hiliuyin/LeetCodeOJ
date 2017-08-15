/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/

void reverseWords(std::string &s)
{
    if (s.empty()) return;
    
    // erase leading spaces
    auto firstNonSpaceChar = s.find_first_not_of(" ");
    s.erase(0, firstNonSpaceChar);
    if (s.empty()) return;
    
    // erase trailing spaces
    auto lastNonSpaceChar = s.find_last_not_of(" ");
    if (lastNonSpaceChar+1 < s.size())
        s.erase(lastNonSpaceChar+1);
    
    // reverse whole string
    std::reverse(s.begin(), s.end());
    
    // erase the multi spaces between words
    int k = 1;
    for (int i = 1, iEnd = (int)s.size(); i < iEnd; ++i)
    {
        if (!(s[i] == s[i-1] && s[i] == ' '))
        {
            s[k++] = s[i];
        }
    }
    s.erase(k);
    
    // reverse words one by one
    for (std::size_t low = 0, high = 0;;)
    {
        low = s.find_first_not_of(" ", low);
        if (low == std::string::npos)
            break;
        high = s.find_first_of(" ", low);
        
        std::reverse(s.begin()+low, (high != std::string::npos) ? s.begin()+high : s.end());
        if (high == std::string::npos)
            break;
        low = high;
    }
}
