#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 1e5 + 5;
const int MOD = 1e9 + 7;

struct mi { // WARNING: needs some adjustment to work with FFT
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

mi dp[mxN][105];

void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N); for(auto &x : A) cin >> x;
    if(A[0] == 0) {
        for(int i = 0; i < 105; i++) {
            dp[0][i] = 1;
        }
    }else {
        dp[0][A[0]] = 1;
    }
    for(int i = 1; i < N; i++) {
        if(A[i] == 0) {
            for(int j = 1; j <= M; j++) {
                dp[i][j] += dp[i - 1][j];
                if(j - 1 > 0) dp[i][j] += dp[i - 1][j - 1];
                if(j + 1 <= M) dp[i][j] += dp[i - 1][j + 1];
            }
        }else {
            dp[i][A[i]] += dp[i - 1][A[i]];
            if(A[i] - 1 > 0) dp[i][A[i]] += dp[i - 1][A[i] - 1];
            if(A[i] + 1 <= M) dp[i][A[i]] += dp[i - 1][A[i] + 1];
        }
    }
    mi ans = 0;
    for(int i = 1; i <= M; i++) {
        ans += dp[N - 1][i];
    }
    cout << (int) ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}