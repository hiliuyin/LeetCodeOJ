// Determine whether an integer is a palindrome. Do this without extra space.

// Solution 1:
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;
    
    int bits = 0;
    int xCopy = x;
    while (xCopy != 0)
    {
        bits++;
        xCopy /= 10;
    }
    
    int divisor = std::pow(10, bits/2);
    int xLeftPart = (bits%2 == 1) ? x/(divisor*10) : x/divisor;
    int xRightPart = x%divisor;
    auto reverseInt = [xLeftPart]() mutable -> int
    {
        int result = 0;
        while (xLeftPart != 0)
        {
            result = result*10 + xLeftPart%10;
            xLeftPart /= 10;
        }
        return result;
    };
    int reversedLeftPart = reverseInt();
    
    return reversedLeftPart == xRightPart;
}

// Solution 2: use long long
bool isPalindrome(int x) {
    if (x < 0) return false;
    
    long long xCopy{x};
    long long y = 0;
    while (xCopy != 0) {
        y = y*10 + xCopy%10;
        xCopy /= 10;
    }
    
    return y == x ? true : false;
}
