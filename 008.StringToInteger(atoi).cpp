/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/

int myAtoi(std::string str)
{
    if (str.empty()) return 0;
    
    const int sz = (int)str.size();
    int pos = 0;
    for (; pos < sz; ++pos)
    {
        if (str[pos] == ' ' || str[pos] == '\t')
            continue;
        break;
    }
    
    if (pos >= sz)
        return 0;
    
    int sign = 1;
    if (str[pos] == '+' || str[pos] == '-')
    {
        if (str[pos] == '-')
            sign = -1;
        pos++;
    }
    
    if (pos >= sz)
        return 0;
    
    if (str[pos] < '0' || str[pos] > '9')
        return 0;
    
    long long result = 0;
    for (int k = pos; k < sz; ++k)
    {
        if (str[k] >= '0' && str[k] <= '9')
        {
            result = result*10 + str[k] - '0';
            if (sign == 1 && result >= INT_MAX)
                break;
            if (sign == -1 && (-result) <= INT_MIN)
                break;
        }
        else
        {
            break;
        }
    }
    
    result *= sign;
    if (result >= INT_MAX)
        return INT_MAX;
    if (result <= INT_MIN)
        return INT_MIN;
    return static_cast<int>(result);
}
