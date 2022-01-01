#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	stack<pair<int, int>> sk;
	sk.push({-1, -1});
	for(int i = 0; i < N; i++) {
		while(A[i] <= sk.top().first) {
			sk.pop();
		}
		assert(!sk.empty());
		cout << sk.top().second + 1 << " ";
		sk.push({A[i], i});
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

