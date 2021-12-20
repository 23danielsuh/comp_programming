#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, M; cin >> N >> M;
	string S; cin >> S; 
	S = '?' + S;
	vector<int> actual(N + 5), pref_min(N + 5), pref_max(N + 5), suff_min(N + 5), suff_max(N + 5);
	for(int i = 1; i <= N; i++) {
		actual[i] = actual[i - 1] + (S[i] == '+' ? 1 : -1);
		pref_max[i] = max(pref_max[i - 1], actual[i]);
		pref_min[i] = min(pref_min[i - 1], actual[i]);
	}
	for(int i = N; i >= 1; i--) {
		if(S[i] == '+') {
			suff_max[i] = max(suff_max[i], suff_max[i + 1] + 1);
			suff_min[i] = min(suff_min[i], suff_min[i + 1] + 1);
		}else {
			suff_max[i] = max(suff_max[i], suff_max[i + 1] - 1);
			suff_min[i] = min(suff_min[i], suff_min[i + 1] - 1);
		}
		cout << suff_min[i] << " ";
	}
	for(int i = 0; i <= N; i++) {
	}
	cout << "\n";
	while(M--) {
		int l, r; cin >> l >> r;
		int X = actual[l - 1];
		int mn = min(pref_min[l - 1], X + suff_min[r + 1]);
		cout << pref_min[l - 1] << " " << X + suff_min[r + 1] << "\n";
		int mx = max(pref_max[l - 1], X + suff_max[r + 1]);
		cout << mx - mn + 1 << "\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

