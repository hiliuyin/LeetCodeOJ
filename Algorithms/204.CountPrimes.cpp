/*
Description:
Count the number of prime numbers less than a non-negative number, n.
*/

int countPrimes(int n) {
    std::vector<bool> prime(n, true);
    prime[0] = false, prime[1] = false;
    for (int i = 0; i < std::sqrt(n); ++i) {
        if (!prime[i]) continue;
        for (int j = i*i; j < n; j += i) {
            prime[j] = false;
        }
    }
    return std::count(prime.begin(), prime.end(), true);
}
