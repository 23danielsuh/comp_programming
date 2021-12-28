#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, M, rb, cb, rd, cd; cin >> N >> M >> rb >> cb >> rd >> cd;
	rb--, cb--, rd--, cd--;
	int cnt = 0;
	int r = 1, c = 1;
	while(true) {
		if(rb == rd || cb == cd) break;
		if(rb == 0) r = 1;
		if(rb == N - 1) r = -1;
		if(cb == 0) c = 1;
		if(cb == M - 1) c = -1;
		rb += r;
		cb += c;
		cnt++;
	}
	cout << cnt << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

