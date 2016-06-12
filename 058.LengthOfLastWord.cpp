/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

int lengthOfLastWord(std::string s)
{
    if (s.empty()) return 0;
    
    int end = (int)s.size()-1;
    for (; end >= 0; --end)
    {
        if (s[end] != ' ')
            break;
    }
    
    if (end < 0) return 0;

    int begin = end;
    for (; begin >= 0; --begin)
    {
        if (s[begin] == ' ')
            break;
    }
    
    return end-begin;
}
