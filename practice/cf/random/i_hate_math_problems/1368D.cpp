#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N; cin >> N;
	vector<int> A(N);
	vector<int> cnt(25, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		for(int j = 0; j < 25; j++) {
			if(A[i] & (1 << j)) {
				cnt[j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++) {
		int cur = 0;
		for(int j = 0; j < 25; j++) {
			if(cnt[j]) {
				cur |= (1 << j);
				cnt[j]--;
			}
		}
		ans += cur * cur;
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
 * 000
 * 001
 * 010
 * 011
 * 100
 * 101
 * 110
 * 111
 * 
 */
