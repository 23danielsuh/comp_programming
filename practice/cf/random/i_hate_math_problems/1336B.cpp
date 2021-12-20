#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int ans = LLONG_MAX;

int square(int x) {
	return 1LL * x * x;
}

void calc(vector<int> &A, vector<int> &B, vector<int> &C) {
	for(auto &x : A) {
		auto b_it = lower_bound(B.begin(), B.end(), x);
		auto c_it = upper_bound(C.begin(), C.end(), x);
		if(b_it == B.end() || c_it == C.begin()) continue;
		c_it--; ans = min(ans, square(x - *b_it) + square(*b_it - *c_it) + square(*c_it - x));
	}
}

void solve() {
    int nr, ng, nb; cin >> nr >> ng >> nb;
	vector<int> R(nr); for(auto &x : R) cin >> x;
	vector<int> G(ng); for(auto &x : G) cin >> x;
	vector<int> B(nb); for(auto &x : B) cin >> x;
	sort(R.begin(), R.end());
	sort(G.begin(), G.end());
	sort(B.begin(), B.end());
	ans = LLONG_MAX;
	calc(R, G, B);
	calc(R, B, G);
	calc(B, R, G);
	calc(B, G, R);
	calc(G, R, B);
	calc(G, B, R);
	cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

