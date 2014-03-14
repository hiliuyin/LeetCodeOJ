// String to Integer (atoi)
// Implement atoi to convert a string to an integer.
// 
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
// 
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
// 
// spoilers alert... click to show requirements for atoi.
// 
// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// 
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// 
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// 
// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
// 

int atoi(const char *str)
{
    if (str == nullptr) return 0;
    
    // skip the spaces
    while (*str == ' '
        || *str == '\n'
        || *str == '\r'
        || *str == '\t'
        || *str == '\v')
        ++str;
    
    if (*str == '\0') return 0;
    
    // consider the negative number
    bool negative = false;
    if (*str == '-'
    && *(str+1) >= '0'
    && *(str+1) <= '9')
    {
        negative = true;
        ++str;
    }
    
    // consider the non-negative number
    if (*str == '+'
        && *(str+1) >= '0'
        && *(str+1) <= '9')
    {
        ++str;
    }
    
    if (*str < '0' || *str > '9') return 0;
    
    uint64_t num = 0;  // use uint64_t type to hold INT_MAX and INT_MIN situations.
    while (*str >= '0' && *str <= '9')
    {
        if (negative && num >= (uint64_t)INT_MAX+1)
        {
            num = INT_MAX+1;
            break;
        }
        else if (!negative && num >= (uint64_t)INT_MAX)
        {
            num = INT_MAX;
            break;
        }
        
        num = num*10 + *str - '0';
        ++str;
    }

    if (negative && num >= (uint64_t)INT_MAX+1)
    {
        num = INT_MAX+1;
    }
    else if (!negative && num >= (uint64_t)INT_MAX)
    {
        num = INT_MAX;
    }
    
    return negative?(-(int)num):(int)num;
}
