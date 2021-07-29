map<ll, int> prime_factor(ll n) {
    map<ll, int> factorization;
    while (n % 2 == 0) {
        factorization[2]++;
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factorization[n]++;
    return factorization;
}
