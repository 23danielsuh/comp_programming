#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
	int N, M; cin >> N >> M;
	vector<vector<int>> grid(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	
	//can you get a value of at least alpha?
	//pigeonhole principle is guaranteed to work!
	//you have to optimally select N - 1 shops
	auto ok = [&](int alpha) -> bool {
		bool has = 0;
		vector<bool> orz(M)m
		for(int i = 0; i < N; i++) {
			int cnt = 0;
			for(int j = 0; j < M; j++) {
				if(grid[i][j] >= alpha) {
					orz[j] = true;
					cnt++;
				}
			}
			if(cnt > 1) has = true;
		}
		if(!has && M > 1) return false;
		for(auto x : orz) {
			if(x == 0) {
				return false;
			}
		}
		return true;
	};
	int lo = 1, hi = 1e10;
	while(lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if(ok(mid)) {
			lo = mid;
		}else {
			hi = mid - 1;
		}
	}
	cout << lo << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

