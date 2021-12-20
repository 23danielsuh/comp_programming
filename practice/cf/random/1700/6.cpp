#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int MOD = 5;

struct mi {
 	int v; explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a;
}
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { assert(a.v != 0); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }

void solve() {
    int N, M; cin >> N >> M;
    MOD = M;
    vector<mi> dp(N + 1, 0);
    dp[1] = 1;
    int sum = 1;
    for(int i = 2; i <= N; i++) {
        dp[i] += sum;
        int z = 2;
        for(; z * z <= i; z++) {
            dp[i] += dp[i / z];
        }
        for(int c = 1, cur = i / z; c <= cur; c++) {
            int l = i / (c + 1) + 1, r = i / c;
            dp[i] += (r - l + 1) * dp[c];
        }
        sum += (int) dp[i];
    }
    cout << (int) dp[N] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

