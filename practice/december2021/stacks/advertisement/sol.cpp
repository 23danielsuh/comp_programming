#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	stack<int> sk;
	vector<ll> areas(N, 0);
	for(int i = 0; i < N; i++) {
		while(!sk.empty() && A[sk.top()] >= A[i]) {
			sk.pop();
		}
		ll cur = i - (sk.empty() ? -1 : sk.top());
		areas[i] += cur * A[i];
		sk.push(i);
	}
	while(!sk.empty()) sk.pop();
	for(int i = N - 1; i >= 0; i--) {
		while(!sk.empty() && A[sk.top()] >= A[i]) {
			sk.pop();
		}
		ll cur =  (sk.empty() ? N : sk.top()) - i - 1;
		areas[i] += cur * A[i];
		sk.push(i);
	}
	cout << *max_element(areas.begin(), areas.end()) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

