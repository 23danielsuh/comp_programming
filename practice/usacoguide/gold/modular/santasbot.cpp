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
    //int64_t x = binpow(8, MOD - 2, MOD);
    //cout << (7 * x) % MOD;
    map<int, int> cnt;
    int N; cin >> N;
    vector<vector<int>> A(N);
    vector<int> K(N);
    for(int i = 0; i < N; i++) {
        cin >> K[i];
        A[i].resize(K[i]);
        for(auto &x : A[i]) {
            cin >> x;
            cnt[x]++;
        }
    }
    vector<int> inv((int) 1e6 + 6);
    for(int i = 0; i <= (int) 1e6 + 5; i++) {
        inv[i] = binpow(i, MOD - 2, MOD);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K[i]; j++) {
            ans += mul(inv[K[i]], inv[N], cnt[A[i][j]], inv[N]);
            ans %= MOD;
        }
    }
    cout << ans;
}

