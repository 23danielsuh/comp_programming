#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

void solve() {
	int N, M; cin >> N >> M;
	DSU dsu(N + 5);
	vector<pair<int, int>> A(M);
	for(int i = 0; i < M; i++) {
		cin >> A[i].first >> A[i].second;
	}
	//connect 2 nodes together;
	int ans = LLONG_MAX;
	pair<pair<int, int>, pair<int, int>> ans_pair;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			DSU dsu(N + 5);
			for(auto &x : A) {
				dsu.unite(x.first, x.second);
			}
			dsu.unite(i, j);
			if(dsu.same_set(1, N)) {
				ans = min(ans, (i - j) * (i - j));
				if((i - j) * (i - j) < ans) {
					ans_pair.first = make_pair(i, j);
				}
			}
		}
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = 1; k <= N; k++) {
				for(int x = 1; x <= N; x++) {
					DSU dsu(N + 5);
					for(auto &cur : A) {
						dsu.unite(cur.first, cur.second);
					}
					dsu.unite(i, j);
					dsu.unite(k, x);
					if(dsu.same_set(1, N)) {
						if((i - j) * (i - j) + (x - k) * (x - k) < ans) {
							ans_pair.first = make_pair(i, j);
							ans_pair.second = make_pair(x, k);
						}
						ans = min(ans, (i - j) * (i - j) + (x - k) * (x - k));
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--) {
		solve();
	}
}
