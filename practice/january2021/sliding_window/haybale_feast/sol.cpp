#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; ll M; cin >> N >> M;
	vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
	ll ans = LLONG_MAX, sum = 0;
	multiset<pair<int, int>> sw;
	int r = 0;
	for(int l = 0; l < N; l++) {
		while(r < N && sum < M) {
			sum += A[r].first;
			sw.insert({A[r].second, A[r].first});
			r++;
		}
		if(sum >= M) {
			ans = min(ans, (ll) (*sw.rbegin()).first);
		}
		sum -= A[l].first;
		sw.erase(sw.find({A[l].second, A[l].first}));
	}
	cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

