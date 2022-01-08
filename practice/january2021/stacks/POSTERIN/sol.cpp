#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
	stack<pair<int, int>> st;
	int ans = 0;
	for(int i = 0; i < N; i++) {
		while(!st.empty() && st.top().second >= A[i].second) {
			ans++;
			st.pop();
		}
		st.push({A[i].first, A[i].second});
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

/*
 *observations:
 *for each building, what do we want to find?
 * a building has to be exactly equal to it for it to contribute a score of 0
 * Well, that building contributes either a score of 0 or 1 depending on if there has been a building in the past that has been equal to it.
 */
