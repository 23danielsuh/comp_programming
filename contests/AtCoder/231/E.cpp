#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N, X; cin >> N >> X;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
	if(X >= A[i]) {
		X /= A[i];
		ans++;
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

