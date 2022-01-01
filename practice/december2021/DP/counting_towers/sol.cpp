#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll 

template <int MOD=998244353>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
		Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

const int mxN = 1e6 + 5;
const int MOD = 1e9 + 7;
Modular<MOD> dp[mxN][2];

void pp() {
	dp[1][0] = dp[1][1] = 1;
	//0 indicates that the past two elements were not joined together, 1 means that they were
	for(int i = 2; i < mxN; i++) {
		dp[i][0] = dp[i - 1][0] * 4 + dp[i - 1][1];
		dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0];
	}
}

void solve() {
	int N; cin >> N;
	cout << dp[N][0] + dp[N][1] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	pp();
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

