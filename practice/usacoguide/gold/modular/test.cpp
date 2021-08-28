#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 998244353
#define int ll

ll binpow(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1)  // if n is odd
			res = res * x % m;
		x = x * x % m;
		n /= 2;  // divide by two
	}
	return res;
}

ll mul(int a, int b, int c, int d) {
    int temp = (a * b) % MOD;
    int temp1 = (c * temp) % MOD;
    return (d * temp1) % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> inv(N + 1);
    for(int i = 0; i <= N; i++) {
        inv[i] = binpow(i, MOD - 2, MOD);
        cout << inv[i] << "\n";
    }
}

