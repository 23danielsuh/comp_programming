#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
	int ans = 0;
	stack<int> st;
	for(int i = 0; i < N; i++) {
		while(!st.empty() && st.top() > A[i].second) {
			st.pop();
		}
		if(st.empty() || st.top() < A[i].second) {
			ans++;
			st.push(A[i].second);
		}
	}
	cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

