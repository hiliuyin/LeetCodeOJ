/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/

// Solution 1: trivial solution
int mySqrt(int x) {
    long k = 0;
    while (k <= x) {
        long product = k * k;
        if (product == x) return k;
        else if (product > x) {
            k = k - 1;
            break;
        }
        k++;
    }
    return k;
}

// Solution 2: binary search
int mySqrt(int x) {
    if (x == 0) return 0;
    int low = 1, high = x, res;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (mid <= x/mid) {
            low = mid + 1;
            res = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return res;
}
