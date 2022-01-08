#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template <int MOD=(int) 1e9 + 7>
struct Mint {
    int value;
    static const int MOD_value = MOD;

    Mint(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Mint(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Mint& operator+=(Mint const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Mint& operator-=(Mint const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Mint& operator*=(Mint const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Mint mexp(Mint a, long long e) {
		Mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
    }
    friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }

    Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Mint const& a) {return os << a.value;}
    friend bool operator==(Mint const& a, Mint const& b) {return a.value == b.value;}
    friend bool operator!=(Mint const& a, Mint const& b) {return a.value != b.value;}
};
#define mint Mint

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> A(N);
	for(auto &x : A) cin >> x.first;
	for(auto &x : A) cin >> x.second;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

/*
 * you can separate the things into its layers? -> but then how do you combine the layers together
 * 1 2
 * 1 2
 *  
 * 5 possible shapes
 *  X
 * XX
 *
 *
 */
