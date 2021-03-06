#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	map<int, int> S, E;
	for(int i = 0; i < N; i++) {
		S[A[i]] = INT_MAX;
		E[A[i]] = INT_MIN;
	}
	for(int i = 0; i < N; i++) {
		S[A[i]] = min(i, S[A[i]]);
		E[A[i]] = max(i, E[A[i]]);
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

