/*
Implement pow(x, n).
*/

double myPow(double x, int n) {
    if (n == 0) return 1.0;

    // must consider the case: if n is INT_MIN
    std::function<double(double, unsigned int)> helper = [&](double x, unsigned int n) -> double
    {
        if (n == 1) return x;
        double temp = helper(x, n/2);
        if (n%2 == 1)
            return temp * temp * x;
        else
            return temp * temp;
    };
        
    double result = helper(x, (n > 0) ? n : -n);
    if (n < 0)
        return 1.0/result;
        
    return result;
}
