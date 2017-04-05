/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

int getSum(int a, int b)
{
    auto calSum = [](int x, int y) {
        int sum = x;
        while (y != 0) {
            sum = x^y;
            y = (x&y) << 1;
            x = sum;
        };
        return sum;
    };
    
    return calSum(a, b);
}
