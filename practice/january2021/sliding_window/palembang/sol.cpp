#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	ll ans = 0;
	int K, N; cin >> K >> N;
	vector<pair<int, int>> A;
	for(int i = 0; i < N; i++) {
		char a, b;
		int x, y;
		cin >> a >> x >> b >> y;
		if(a == b) {
			ans += abs(y - x);
		}else {
			A.push_back(make_pair(min(x, y), max(x, y)));
		}
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

