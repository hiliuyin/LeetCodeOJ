/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False
*/

// Solution 1: 1 + 3 + 5 + 7 + 9 + ..... + k = k * (1 + 2*(k-1) + 1)/2 = k^2
bool isPerfectSquare(int num) {
    int k = 1;
    while (num > 0) {
        num -= k;
        k += 2;
    }
    return num == 0;
}

// Solution 2: binary search
bool isPerfectSquare(int num) {
    int low = 0, high = num;
    while (low <= high) {
        long long mid = low + (high - low)/2;
        long long product = mid * mid;
        if (product > num) high = mid-1;
        else if (product < num) low = mid+1;
        else return true;
    }
    return false;
}
