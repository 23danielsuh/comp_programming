#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	int mx = 0;
	vector<int> A(N); for(auto &x : A) cin >> x;
	set<int> sw;
	int r = 0;
	for(int l = 0; l < N; l++) {
		while(r < N && !sw.count(A[r])) {
			sw.insert(A[r]);
			r++;
		}
		sw.erase(sw.find(A[l]));
		mx = max(mx, r - l);
	}
	cout << mx << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

