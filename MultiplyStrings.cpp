// Multiply Strings
// Given two numbers represented as strings, return multiplication of the numbers as a string.
// 
// Note: The numbers can be arbitrarily large and are non-negative.

string sum(const string &s1, const string &s2)
{
    string result;

    int i1 = 0;
    int i2 = 0;
    
    int carry = 0;
    int rem = 0;
    while (i1 < s1.size() && i2 < s2.size())
    {
        int sum = s1[i1]-'0'+s2[i2]-'0'+carry;
        rem = sum%10;
        carry = sum/10;
        result.push_back(rem+'0');
        ++i1;
        ++i2;
    }
    
    if (i1 == s1.size() && i2 == s2.size())
    {
        if (carry != 0)
            result.push_back(carry+'0');
    }
    else if (i1 == s1.size() && i2 != s2.size())
    {
        for (; i2 < s2.size(); ++i2)
        {
            int sum = s2[i2]-'0'+carry;
            carry = sum/10;
            result.push_back(sum%10 + '0');
        }
        if (carry != 0)
            result.push_back(carry+'0');
    }
    else  // if (i1 != s1.size() && i2 == s2.size())
    {
        for (; i1 < s1.size(); ++i1)
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

string multiply(string num1, string num2)
{
    string result;
    
    if ((num1.size() == 1 && num1[0] == '0')
        || (num2.size() == 1 && num2[0] == '0'))
        return {"0"};

    for (int i = (int)num2.size()-1; i >= 0; --i)
    {
        int carry = 0;
        int rem = 0;
        string s;

        if (num2[i] != '0')
        {
            for (int k = 0; k < num2.size()-i-1; ++k)
                s.push_back('0');

            for (int j = (int)num1.size()-1; j >= 0; --j)
            {
                int n = (num1[j]-'0')*(num2[i]-'0') + carry;
                carry = n/10;
                rem = n%10;
            
                s.push_back(rem+'0');
            }
        
            if (carry != 0)
                s.push_back(carry+'0');
            
            if (result.size() == 0)
                result = s;
            else
            {
                result = sum(result, s);
            }
        }
    }
    
    std::reverse(result.begin(), result.end());
    
    return result;
}
