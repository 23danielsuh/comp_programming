#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	map<int, int> cnt;
	for(auto &x : A) {
		cin >> x;
		cnt[x]++;
	}
	int ans = (int) cnt.size();
	for(auto &x : cnt) {
		if(x.second >= 2 && cnt[-x.first] == 0) {
			ans++;
		}
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

