#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
    DSU dsu(N + 1);
    vector<char> cur(N + 1);
    for(int i = 0; i < M; i++) {
        int a, b; char c; cin >> a >> b >> c;
        if(dsu.same_set(a, b)) {
            if(cur[dsu.get(a)] != c) {
                cout << i << "\n";
                return;
            }
            cur[a] = c; 
            cur[b] = c;
        }else {
            dsu.unite(a, b);
        }
    }
    cout << M << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("truth.in", "r", stdin);
    //freopen("truth.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
