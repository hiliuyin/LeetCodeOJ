/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/

std::string sum(const std::string &s1, const std::string &s2)
{
    std::string result;
    
    const int sz1 = (int)s1.size();
    const int sz2 = (int)s2.size();
    
    int i1 = 0;
    int i2 = 0;
    int carry = 0;
    int rem = 0;
    while (i1 < sz1 && i2 < sz2)
    {
        int sum = s1[i1] - '0' + s2[i2] - '0' + carry;
        rem = sum%10;
        carry = sum/10;
        result.push_back(rem+'0');
        ++i1;
        ++i2;
    }
    
    if (i1 == sz1 && i2 == sz2)
    {
        if (carry != 0)
            result.push_back(carry+'0');
    }
    else if (i1 == sz1 && i2 != sz2)
    {
        for (; i2 < sz2; ++i2)
        {
            int sum = s2[i2]-'0'+carry;
            carry = sum/10;
            result.push_back(sum%10 + '0');
        }
        if (carry != 0)
            result.push_back(carry+'0');
    }
    else  // if (i1 != sz1 && i2 == sz2)
    {
        for (; i1 < sz1; ++i1)
        {
            int sum = s1[i1]-'0'+carry;
            carry = sum/10;
            result.push_back(sum%10 + '0');
        }
        if (carry != 0)
            result.push_back(carry+'0');
    }
    
    return result;
}

std::string multiply(std::string num1, std::string num2)
{
    const int sz1 = (int)num1.size();
    const int sz2 = (int)num2.size();
    
    if ((sz1 == 1 && num1[0] == '0')
     || (sz2 == 1 && num2[0] == '0'))
        return "0";
    
    if (sz1 == 1 && num1[0] == '1') return num2;
    if (sz2 == 1 && num2[0] == '1') return num1;
    
    std::string result;
    for (int i = sz2-1; i >= 0; --i)
    {
        int carry = 0;
        int rem = 0;
        std::string s;
        
        if (num2[i] != '0')
        {
            s.append(sz2-i-1, '0');
            
            for (int j = sz1-1; j >= 0; --j)
            {
                int n = (num1[j]-'0')*(num2[i]-'0') + carry;
                carry = n/10;
                rem = n%10;
                
                s.push_back(rem+'0');
            }
            
            if (carry != 0)
                s.push_back(carry+'0');
            
            if (result.empty())
                result = s;
            else
                result = sum(result, s);
        }
    }
    
    std::reverse(result.begin(), result.end());
    
    return result;
}
