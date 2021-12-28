#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

void solve() {
	int N; ll K; cin >> N >> K;
	vector<int> A(N);
	for(auto &x : A) {
		cin >> x;
	}
	sort(A.begin(), A.end());
	vector<ll> psum(N + 1);
	for(int i = 0; i < N; i++) {
		psum[i + 1] = psum[i] + A[i];
	}
	ll ans = LLONG_MAX;
	for(int i = 0; i < N; i++) {
		//removing a certain number of elements in the range of [0, N - 2]
		ll sum = psum[N - i] + A[0] * i;
		ll cur = i;
		if(sum > K) {
			ll diff = sum - K;
			cur += cdiv(diff, i + 1);
		}
		ans = min(ans, cur);
	}
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
