/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

int getSum(int a, int b)
{
    auto calSum = [](int x, int y)
    {
        int xorVal = 0;
        int andVal = 0;
        
        while (y != 0)
        {
            xorVal = x ^ y;
            andVal = x & y;
            
            andVal <<= 1;

            x = xorVal;
            y = andVal;
        }

        return xorVal;
    };
    
    return calSum(a, b);
}
